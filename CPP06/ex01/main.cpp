#include "Serializer.hpp"

int main()
{
    Data    mydata(123, "DATAAA");

    std::cout << "Mydata'id = " <<mydata.id << std::endl;
    std::cout << "Mydata'name = " <<mydata.name << std::endl;

    uintptr_t   raw = Serializer::serialize(&mydata);

    std::cout << "raw's value = " << raw <<  std::endl;

    Data    *deserializedData = Serializer::deserialize( raw );

    std::cout <<  "deserializedData's id = " << deserializedData->id << std::endl;
    std::cout <<  "deserializedData's name = " << deserializedData->name << std::endl;

}