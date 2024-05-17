#include "../inc/payload-builder.h"

PayloadBuilder::PayloadBuilder() {
    this->_arena = std::make_unique<google::protobuf::Arena>();
}

PayloadBuilder::~PayloadBuilder() {
    this->_arena.reset();
}

PayloadBuilder& PayloadBuilder::setEvent(PAYLOAD::Events event) {
    this->_event = event;
    return *this;
}

PayloadBuilder& PayloadBuilder::reset() {
    this->_event = PAYLOAD::Events::NONE;
    this->_uid = "";
    this->_rid = "";
    this->_oid = "";
    this->_msg = "";
    return *this;
}

PayloadBuilder& PayloadBuilder::setUserId(std::string UID) {
    this->_uid = UID;
    return *this;
}

PayloadBuilder& PayloadBuilder::setRoomId(std::string RID) {
    this->_rid = RID;
    return *this;
}

PayloadBuilder& PayloadBuilder::setOpponentId(std::string OID) {
    this->_oid = OID;
    return *this;
}

PayloadBuilder& PayloadBuilder::setMessage(std::string MSG) {
    this->_msg = MSG;
    return *this;
}

PAYLOAD::Payload* PayloadBuilder::newPayload() {
    return google::protobuf::Arena::CreateMessage<PAYLOAD::Payload>(this->_arena.get());
}

PayloadBuilder& PayloadBuilder::build(PAYLOAD::Payload* payload) {
    payload->set_event(this->_event);
    payload->mutable_data()->set_userid(this->_uid);
    payload->mutable_data()->set_opponentid(this->_oid);
    payload->mutable_data()->set_roomid(this->_rid);
    payload->mutable_data()->set_msg(this->_msg);
    this->reset();
    return *this;
}
