#pragma once 

#include "../src/proto/payload.pb.h"
#include <google/protobuf/arena.h>

class PayloadBuilder {
public:
    PayloadBuilder();
    ~PayloadBuilder();

    PayloadBuilder& setEvent(PAYLOAD::Events event);   
    PayloadBuilder& setUserId(std::string UID);
    PayloadBuilder& setRoomId(std::string RID);
    PayloadBuilder& setOpponentId(std::string OID);
    PayloadBuilder& setMessage(std::string MSG);
    

    PayloadBuilder& reset();
    PAYLOAD::Payload* newPayload();
    PayloadBuilder& build(PAYLOAD::Payload* payload);

private:
    std::string _uid = "";
    std::string _rid = "";
    std::string _oid = "";
    std::string _msg = "";
    PAYLOAD::Events _event = PAYLOAD::Events::NONE;

    std::unique_ptr<google::protobuf::Arena> _arena;

};