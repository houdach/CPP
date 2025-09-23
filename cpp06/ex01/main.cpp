#include "Serializer.hpp"

int main() {
    Data d;
    d.id = 42;
    d.name = "Hello Serializer";

    Data* ptr = &d;

    uintptr_t raw = Serializer::serialize(ptr);
    std::cout << "Serialized value: " << raw << std::endl;

    Data* back = Serializer::deserialize(raw);

    if (ptr == back) {
        std::cout << "Success ✅ : The pointers match!" << std::endl;
        std::cout << "Deserialized Data -> id: " << back->id
                  << ", name: " << back->name << std::endl;
    } else {
        std::cout << "Error ❌ : The pointers do not match!" << std::endl;
    }

    return 0;
}
