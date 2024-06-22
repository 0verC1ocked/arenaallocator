#pragma once 

#include "../src/proto/payload.pb.h"
#include "../src/proto/match.pb.h"
#include "../src/proto/ipc.pb.h"
#include <google/protobuf/arena.h>

class ArenaAllocator {
private:
    std::unique_ptr<google::protobuf::Arena> _arena;
public:
    ArenaAllocator();
    ~ArenaAllocator();

    PAYLOAD::Payload* newPayload();
    
    MATCH::CreateMatchRequest* newCreateMatchRequest();

    IPC::IPCMessage* newIPCMessage();

};
