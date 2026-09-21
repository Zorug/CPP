#include <iostream>
#include "../include/Serializer.hpp"

int main() {
    // 1. Create a non-empty Data object
    Data data;
    data.name = "42 Student";
    data.value = 42;

    // 2. Get the original pointer address
    Data* originalPtr = &data;

    std::cout << "Original pointer address: " << originalPtr << std::endl;

    // 3. Serialize: Convert pointer to uintptr_t
    uintptr_t raw = Serializer::serialize(originalPtr);
    std::cout << "Serialized raw integer:  " << raw << std::endl;

    // 4. Deserialize: Convert uintptr_t back to Data*
    Data* deserializedPtr = Serializer::deserialize(raw);
    std::cout << "Deserialized address:     " << deserializedPtr << std::endl;

    // 5. Verify equality and check content
    if (deserializedPtr == originalPtr) {
        std::cout << "\n[SUCCESS] The deserialized pointer is equal to the original pointer!" << std::endl;
        std::cout << "Data content -> Name: " << deserializedPtr->name 
                  << ", Value: " << deserializedPtr->value << std::endl;
    } else {
        std::cout << "\n[ERROR] Pointers do not match!" << std::endl;
    }

    return 0;
}