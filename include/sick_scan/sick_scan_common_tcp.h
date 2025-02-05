#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
/*
 * Copyright (C) 2013, Freiburg University
 * All rights reserved.
 * 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*       http://www.apache.org/licenses/LICENSE-2.0
*
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*   See the License for the specific language governing permissions and
*   limitations under the License.
*
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * Neither the name of Osnabrueck University nor the names of its
*       contributors may be used to endorse or promote products derived from
*       this software without specific prior written permission.
*     * Neither the name of SICK AG nor the names of its
*       contributors may be used to endorse or promote products derived from
*       this software without specific prior written permission
*     * Neither the name of Ing.-Buero Dr. Michael Lehning nor the names of its
*       contributors may be used to endorse or promote products derived from
*       this software without specific prior written permission
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
 *
 *  Created on: 15.11.2013
 *
 *      Authors:
 *         Christian Dornhege <c.dornhege@googlemail.com>
 */

#ifndef SICK_TIM3XX_COMMON_TCP_H
#define SICK_TIM3XX_COMMON_TCP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#undef NOMINMAX // to get rid off warning C4005: "NOMINMAX": Makro-Neudefinition

#include "sick_scan_common.h"
#include "sick_generic_parser.h"
#include "template_queue.h"

namespace sick_scan
{
/* class prepared for optimized time stamping */

  class DatagramWithTimeStamp
  {
  public:
    DatagramWithTimeStamp(rosTime timeStamp_, std::vector<unsigned char> datagram_)
    {
      timeStamp = timeStamp_;
      datagram = datagram_;
    }

    virtual std::vector<unsigned char> & data(void) { return datagram; }

// private:
    rosTime timeStamp;
    std::vector<unsigned char> datagram;
  };


  class SickScanCommonTcp : public SickScanCommon
  {
  public:
    static void disconnectFunctionS(void *obj);

    SickScanCommonTcp(const std::string &hostname, const std::string &port, int &timelimit, rosNodePtr nh, SickGenericParser *parser,
                      char cola_dialect_id);

    virtual ~SickScanCommonTcp();

    static void readCallbackFunctionS(void *obj, UINT8 *buffer, UINT32 &numOfBytes);

    void readCallbackFunction(UINT8 *buffer, UINT32 &numOfBytes);

    void setReplyMode(int _mode);

    int getReplyMode();

    void setEmulSensor(bool _emulFlag);

    bool getEmulSensor();

    bool stopScanData(bool force_immediate_shutdown = false);

    int numberOfDatagramInInputFifo();

    SopasEventMessage findFrameInReceiveBuffer();

    void processFrame(rosTime timeStamp, SopasEventMessage &frame);

    int reinit(rosNodePtr nh, int delay_millisec);

    virtual int init_device();

    virtual int close_device();

    bool isConnected() { return m_nw.isConnected(); }

    // Queue<std::vector<unsigned char> > recvQueue;
    Queue<DatagramWithTimeStamp> recvQueue;
    UINT32 m_alreadyReceivedBytes;
    UINT32 m_lastPacketSize;
    UINT8 m_packetBuffer[480000];
/**
 * Read callback. Diese Funktion wird aufgerufen, sobald Daten auf der Schnittstelle
 * hereingekommen sind.
 */

  protected:
    void disconnectFunction();

    void readCallbackFunctionOld(UINT8 *buffer, UINT32 &numOfBytes);

    /// Send a SOPAS command to the device and print out the response to the console.
    virtual int sendSOPASCommand(const char *request, std::vector<unsigned char> *reply, int cmdLen, bool wait_for_reply = true);

    /// Read a datagram from the device.
    /**
     * \param [out] recvTimeStamp timestamp of received datagram
     * \param [in] receiveBuffer data buffer to fill
     * \param [in] bufferSize max data size to write to buffer (result should be 0 terminated)
     * \param [out] actual_length the actual amount of data written
     * \param [in] isBinaryProtocol true=binary False=ASCII
     * \param [in] datagram_keywords keyword in returned datagram, e.g. { "LMDscandata" } to get scandata telegrams, or {} (empty vector) for next received datagram
     */
    virtual int
    get_datagram(rosNodePtr nh, rosTime &recvTimeStamp, unsigned char *receiveBuffer, int bufferSize, int *actual_length,
                 bool isBinaryProtocol, int *numberOfRemainingFifoEntries, const std::vector<std::string>& datagram_keywords);

    // Helpers for boost asio
    virtual int readWithTimeout(size_t timeout_ms, char *buffer, int buffer_size, int *bytes_read, const std::vector<std::string>& datagram_keywords);

    /*void handleRead(boost::system::error_code error, size_t bytes_transfered);*/

    /*void checkDeadline();*/

  private:


    // Response buffer
    UINT32 m_numberOfBytesInResponseBuffer; ///< Number of bytes in buffer
    UINT8 m_responseBuffer[1024]; ///< Receive buffer for everything except scan data and eval case data.
    Mutex m_receiveDataMutex; ///< Access mutex for buffer

    // Receive buffer
    UINT32 m_numberOfBytesInReceiveBuffer; ///< Number of bytes in buffer
    UINT8 m_receiveBuffer[480000]; ///< Low-Level receive buffer for all data

    bool m_beVerbose;
    bool m_emulSensor;

    //boost::asio::io_service io_service_;
    //boost::asio::deadline_timer deadline_;
    //boost::asio::streambuf input_buffer_;
    //boost::system::error_code ec_;
    size_t bytes_transfered_;

    std::string hostname_;
    std::string port_;
    int timelimit_;
    int m_replyMode;
  };


} /* namespace sick_scan */
#endif /* SICK_TIM3XX_COMMON_TCP_H */

