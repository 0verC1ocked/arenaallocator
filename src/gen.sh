protoc -I=./proto --cpp_out=./proto --go_out=./proto --csharp_out=./proto proto/payload.proto --experimental_allow_proto3_optional
protoc -I=./proto --cpp_out=./proto --go_out=./proto --csharp_out=./proto proto/match.proto --experimental_allow_proto3_optional

protoc -I=./proto --go_out=./proto --cpp_out=./proto proto/relay.proto --experimental_allow_proto3_optional
