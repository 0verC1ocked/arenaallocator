#include "../inc/arena-allocator.h"

ArenaAllocator::ArenaAllocator() {
    this->_arena = std::make_unique<google::protobuf::Arena>();
}

ArenaAllocator::~ArenaAllocator() {
    this->_arena.reset();
}

PAYLOAD::Payload* ArenaAllocator::newPayload() {
    return google::protobuf::Arena::CreateMessage<PAYLOAD::Payload>(this->_arena.get());
}

MATCH::CreateMatchRequest* ArenaAllocator::newCreateMatchRequest() {
    return google::protobuf::Arena::CreateMessage<MATCH::CreateMatchRequest>(this->_arena.get());
}

IPC::IPCMessage* ArenaAllocator::newIPCMessage() {
    return google::protobuf::Arena::CreateMessage<IPC::IPCMessage>(this->_arena.get());
}
