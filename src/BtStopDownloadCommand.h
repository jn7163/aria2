/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2009 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#ifndef _D_BT_STOP_DOWNLOAD_COMMAND_H_
#define _D_BT_STOP_DOWNLOAD_COMMAND_H_

#include "TimeBasedCommand.h"
#include "SharedHandle.h"

namespace aria2 {

class RequestGroup;
class PieceStorage;
class PeerStorage;
class BtRuntime;

// Stop downloading torrent if in consecutive _timeout seconds,
// download speed is zero and the number of seeder is 0.
class BtStopDownloadCommand:public TimeBasedCommand {
private:
  RequestGroup* _requestGroup;
  
  time_t _timeout;

  Time _checkPoint;

  SharedHandle<BtRuntime> _btRuntime;

  SharedHandle<PeerStorage> _peerStorage;

  SharedHandle<PieceStorage> _pieceStorage;
public:
  BtStopDownloadCommand
  (int32_t cuid,
   RequestGroup* requestGroup,
   DownloadEngine* e,
   time_t timeout);

  virtual void preProcess();

  virtual void process();

  void setBtRuntime(const SharedHandle<BtRuntime>& btRuntime)
  {
    _btRuntime = btRuntime;
  }

  void setPieceStorage(const SharedHandle<PieceStorage>& pieceStorage)
  {
    _pieceStorage = pieceStorage;
  }

  void setPeerStorage(const SharedHandle<PeerStorage>& peerStorage)
  {
    _peerStorage = peerStorage;
  }
};

} // namespace aria2

#endif // _D_BT_STOP_DOWNLOAD_COMMAND_H_