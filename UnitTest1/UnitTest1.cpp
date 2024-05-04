#include "pch.h"
#include "CppUnitTest.h"
#include "../LB_12.3_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(CreateListTest)
        {
            int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            int size = sizeof(values) / sizeof(values[0]);
            Node* head = createListRecursive(nullptr, nullptr, values, 0, size);

            Node* current = head;
            for (int i = 0; i < size; ++i) {
                Assert::IsNotNull(current);
                Assert::AreEqual(values[i], current->data);
                current = current->next;
            }

            deleteListRecursive(head);
        }

        

    };
}