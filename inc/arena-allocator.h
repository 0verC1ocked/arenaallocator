#pragma once 

#include "../src/proto/payload.pb.h"
#include "../src/proto/match.pb.h"
#include "../src/proto/ipc.pb.h"
#include <google/protobuf/arena.h>

class ArenaAllocator {
private:
    ArenaAllocator();
    std::unique_ptr<google::protobuf::Arena> _arena;
public:
    ~ArenaAllocator();

    PAYLOAD::Payload* newPayload();
    
    MATCH::CreateMatchRequest* newCreateMatchRequest();

    IPC::IPCMessage* newIPCMessage();

};
