
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ListClass.h"
//#include "List.h"

using testing::Eq;
using  namespace std;
using testing::Types;

//Tests of push_back method
TEST(MyListTest, testPushBack){
    MyList<int> testList;
    testList.push_back(1);
    EXPECT_EQ(1, testList.getHead()->getData());
    EXPECT_EQ(1, testList.getTail()->getData());
}

//Testing pushing back second element
TEST(MyListTest, testPushBackSecond) {
    MyList<int> testList;
    testList.push_back(1);
    testList.push_back(2);
    EXPECT_EQ(1, testList.getHead()->getData());
    EXPECT_EQ(2, testList.getTail()->getData());
}


//Tests of push_front method
TEST(MyListTest, testPushFront){
    MyList<int> testList;
    testList.push_front(1);
    EXPECT_EQ(1, testList.getHead()->getData());
    EXPECT_EQ(1, testList.getTail()->getData());
}


//Testing pushing front second element
TEST(MyListTest, testPushFrontSecond){
    MyList<int> testList;
    testList.push_front(1);
    testList.push_front(2);
    EXPECT_EQ(2, testList.getHead()->getData());
    EXPECT_EQ(1, testList.getTail()->getData());
}

//Tests of get_size method
TEST(MyListTest, testGetSize) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    EXPECT_EQ(5, testList.get_size());
}

//Tests of pop_front method
TEST(MyListTest, testPopFront) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    int old_size = testList.get_size();
    testList.pop_front();
    EXPECT_EQ(old_size - 1, testList.get_size());
}

//Test of poping front last element
TEST(MyListTest, testPopFrontLast) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    int old_size = testList.get_size();
    testList.pop_front();
    testList.pop_front();
    testList.pop_front();
    testList.pop_front();
    testList.pop_front();
    EXPECT_EQ(old_size - 5, testList.get_size());
}

//Test of pop_front, when there is no elements
TEST(MyListTest, testPopFrontNothing) {
    MyList<int> testList;
    try {
        testList.pop_front();
    }
    catch(out_of_range error) {
        ASSERT_STRCASEEQ("There is no element to delete", error.what());
    }
}

//Tests of pop_back method
TEST(MyListTest, testPopBack) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    int old_size = testList.get_size();
    testList.pop_back();
    EXPECT_EQ(old_size - 1, testList.get_size());
}

//Testing pop back last element
TEST(MyListTest, testPopBackLast) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    int old_size = testList.get_size();
    testList.pop_back();
    testList.pop_back();
    testList.pop_back();
    testList.pop_back();
    EXPECT_EQ(old_size - 4, testList.get_size());
}

//Test of pop back, when there is no elements
TEST(MyListTest, testPopBackNothing) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    try {
        testList.pop_front();
    }
    catch (out_of_range error) {
        ASSERT_STRCASEEQ("There is no element to delete", error.what());
    }
}

//Tests of at method
TEST(MyListTest, testAt) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    Element<int> testElement;
    testElement = testList.at(2);
    EXPECT_EQ(3, testElement.getData());
}

//Testing adding new elements at last position
TEST(MyListTest, testAt4) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    Element<int> testElement;
    testElement = testList.at(4);
    EXPECT_EQ(5, testElement.getData());
}

//Testing adding at first position
TEST(MyListTest, testAt1) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    Element<int> testElement;
    testElement = testList.at(1);
    EXPECT_EQ(2, testElement.getData());    
}

//Testing adding at first element
TEST(MyListTest, testAt0) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    Element<int> testElement;
    try {
        testElement = testList.at(0);
    }
    catch (out_of_range error) {
        ASSERT_STRCASEEQ("Index is greater than list size", error.what());
    }
}

//Tests of insert method
TEST(MyListTest, testInsert) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    Element<int> testElement;
    testList.insert(17, 3);
    testElement = testList.at(3);
    EXPECT_EQ(17, testElement.getData());
}

//Testing of inserting at head
TEST(MyListTest, testInsertHead) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    Element<int> *testElement;
    testList.insert(34, 0);
    testElement = testList.getHead();
    EXPECT_EQ(34, testElement->getData());
}

//Testing inserting in wrong position
TEST(MyListTest, testInsertWrong) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    Element<int> *testElement;
    try {
        testList.insert(25, 25);
    }
    catch (out_of_range error) {
        ASSERT_STRCASEEQ("Index is greater than list size", error.what());
    }  
}

//Tests of remove method
TEST(MyListTest, testRemove) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    Element<int> testElement;
    testList.remove(3);
    testElement = testList.at(3);
    EXPECT_NE(3, testElement.getData());
}

//Testing removing last element
TEST(MyListTest, testRemoveLast) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    testList.remove(4);
    EXPECT_NE(5, testList.getTail()->getData());
}

//Testing of removing wrong element
TEST(MyListTest, testRemoveWrong) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    try {
        testList.remove(5);
    }
    catch (out_of_range error) {
        ASSERT_STRCASEEQ("Index is greater than list size", error.what());
    }
}

//Testing isEmpty method  
TEST(MyListTest, testIsEmpty) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    EXPECT_FALSE(testList.isEmpty());
    testList.clear();
    EXPECT_TRUE(testList.isEmpty());
}

//Testing clear method
TEST(MyListTest, testClear) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    testList.clear();
    EXPECT_EQ(nullptr, testList.getHead());
    EXPECT_EQ(nullptr, testList.getTail());
    EXPECT_EQ(0, testList.get_size());
}

//Testing set method
TEST(MyListTest, testSet) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    Element<int> testElement;
    testList.set(17, 3);
    testElement = testList.at(3);
    EXPECT_EQ(17, testElement.getData());
}

//Testing setting the tail element
TEST(MyListTest, testSetTail) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    Element<int> *testElement;
    testList.set(34, testList.get_size() - 1);
    testElement = testList.getTail();
    EXPECT_EQ(34, testElement->getData());
}

//Testing setting the head element
TEST(MyListTest, testSetHead) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    Element<int> *testElement;
    testList.set(77, 0);
    testElement = testList.getHead();
    EXPECT_EQ(77, testElement->getData());
}

//Testing setting wrong element
TEST(MyListTest, testSetNothing) {
    MyList<int> testList = {1, 2, 3, 4, 5};
    try {
        testList.set(6, 89);
    }
    catch (out_of_range error) {
        ASSERT_STRCASEEQ("Index is greater than list size", error.what());
    }
}

/*
Char section
*/

//Tests of push_back method
TEST(MyListTest, testPushBackChar){
    MyList<char> testList;
    testList.push_back('1');
    EXPECT_EQ('1', testList.getHead()->getData());
    EXPECT_EQ('1', testList.getTail()->getData());
    testList.push_back('2');
    EXPECT_EQ('1', testList.getHead()->getData());
    EXPECT_EQ('2', testList.getTail()->getData());
}

//Testing pushing back second element
TEST(MyListTest, testPushBackCharSecond){
    MyList<char> testList;
    testList.push_back('1');
    testList.push_back('2');
    EXPECT_EQ('1', testList.getHead()->getData());
    EXPECT_EQ('2', testList.getTail()->getData());
}

//Tests of push_front method
TEST(MyListTest, testPushFrontChar) {
    MyList<char> testList;
    testList.push_front('1');
    EXPECT_EQ('1', testList.getHead()->getData());
    EXPECT_EQ('1', testList.getTail()->getData());
    testList.push_front('2');
    EXPECT_EQ('2', testList.getHead()->getData());
    EXPECT_EQ('1', testList.getTail()->getData());
}

//Testing pushing front second element
TEST(MyListTest, testPushFrontCharSecond) {
    MyList<char> testList;
    testList.push_front('1');
    testList.push_front('2');
    EXPECT_EQ('2', testList.getHead()->getData());
    EXPECT_EQ('1', testList.getTail()->getData());
}

//Tests of pop_front method
TEST(MyListTest, testPopFrontChar) {
    MyList<char> testList = {'1', '2', '3', '4', '5'};
    int old_size = testList.get_size();
    testList.pop_front();
    EXPECT_EQ(old_size - 1, testList.get_size());
}

//Test of poping front last element
TEST(MyListTest, testPopFrontCharLast) {
    MyList<char> testList = {'1', '2', '3', '4', '5'};
    int old_size = testList.get_size();
    testList.pop_front();
    testList.pop_front();
    testList.pop_front();
    testList.pop_front();
    testList.pop_front();
    EXPECT_EQ(old_size - 5, testList.get_size());
}

//Test of pop_front, when there is no elements
TEST(MyListTest, testPopFrontCharNothing) {
    MyList<char> testList;
    try {
        testList.pop_front();
    }
    catch (out_of_range error) {
        ASSERT_STRCASEEQ("There is no element to delete", error.what());
    }
}

//Tests of pop_back method
TEST(MyListTest, testPopBackChar) {
    MyList<char> testList = {'1', '2', '3', '4', '5'};
    int old_size = testList.get_size();
    testList.pop_back();
    EXPECT_EQ(old_size - 1, testList.get_size());
}

//Testing pop_back second element
TEST(MyListTest, testPopBackCharSecond) {
    MyList<char> testList = {'1', '2', '3', '4', '5'};
    int old_size = testList.get_size();
    testList.pop_back();
    testList.pop_back();
    testList.pop_back();
    testList.pop_back();
    EXPECT_EQ(old_size - 4, testList.get_size());
}

//Test of pop back, when there is no elements
TEST(MyListTest, testPopBackCharNothing) {
    MyList<char> testList;
    try {
        testList.pop_front();
    }
    catch (out_of_range error) {
        ASSERT_STRCASEEQ("There is no element to delete", error.what());
    }
}

//Tests of at method
TEST(MyListTest, testAtChar) {
    MyList<char> testList = {'1', '2', '3', '4', '5'};
    Element<char> testElement;
    testElement = testList.at(2);
    EXPECT_EQ('3', testElement.getData());
    testElement = testList.at(4);
}

//Testing at fourth position
TEST(MyListTest, testAtChar4) {
    MyList<char> testList = {'1', '2', '3', '4', '5'};
    Element<char> testElement;
    testElement = testList.at(4);
    EXPECT_EQ('5', testElement.getData());
}

//Testing at first element
TEST(MyListTest, testAtChar1) {
    MyList<char> testList = {'1', '2', '3', '4', '5'};
    Element<char> testElement;
    testElement = testList.at(0);
    EXPECT_EQ('2', testElement.getData());
}

//Testing at wrong position
TEST(MyListTest, testAtCharNothing) {
    MyList<char> testList = {'1', '2', '3', '4', '5'};
    Element<char> testElement;
    try {
        testElement = testList.at(-1);
    }
    catch (out_of_range error) {
        ASSERT_STRCASEEQ("Index is greater than list size", error.what());
    }
}

//Tests of insert method
TEST(MyListTest, testInsertChar) {
    MyList<char> testList = {'1', '2', '3', '4', '5'};
    Element<char> testElement;
    testList.insert('a', 3);
    testElement = testList.at(3);
    EXPECT_EQ('a', testElement.getData());
}

//Test inserting first element
TEST(MyListTest, testInsertCharFirst) {
    MyList<char> testList = {'1', '2', '3', '4', '5'};
    Element<char> *testElement;
    testList.insert('f', 0);
    testElement = testList.getHead();
    EXPECT_EQ('f', testElement->getData());
}

//Test inserting in wrong position
TEST(MyListTest, testInsertCharNothing) {
    MyList<char> testList = {'1', '2', '3', '4', '5'};
    try {
        testList.insert('y', 25);
    }
    catch (out_of_range error) {
        ASSERT_STRCASEEQ("Index is greater than list size", error.what());
    }
}

//Tests of remove method
TEST(MyListTest, testRemoveChar) {
    MyList<char> testList = {'a', 'b', 'c', 'd', 'e'};
    Element<char> testElement;
    testList.remove(3);
    testElement = testList.at(3);
    EXPECT_NE('d', testElement.getData());
}

//Test removing first element
TEST(MyListTest, testRemoveCharFirst) {
    MyList<char> testList = {'a', 'b', 'c', 'd', 'e'};
    Element<char> *testElement;
    testList.remove(0);
    testElement = testList.getHead();
    EXPECT_NE('a', testElement->getData());
}

//Test removing wrong element
TEST(MyListTest, testRemoveCharNothing) {
    MyList<char> testList = {'a', 'b', 'c', 'd', 'e'};
    try {
        testList.remove(8);
    }
    catch (out_of_range error) {
        ASSERT_STRCASEEQ("Index is greater than list size", error.what());
    }
}

//Test clear method
TEST(MyListTest, testClearChar) {
    MyList<char> testList = {'a', 'b', 'c', 'd', 'e'};
    testList.clear();
    EXPECT_EQ(nullptr, testList.getHead());
    EXPECT_EQ(nullptr, testList.getTail());
    EXPECT_EQ(0, testList.get_size());
    testList.clear();
    EXPECT_EQ(nullptr, testList.getHead());
    EXPECT_EQ(nullptr, testList.getTail());
    EXPECT_EQ(0, testList.get_size());
}

//Test set method
TEST(MyListTest, testSetChar) {
    MyList<char> testList = {'a', 'b', 'c', 'd', 'e'};
    Element<char> testElement;
    testList.set('k', 3);
    testElement = testList.at(3);
    EXPECT_EQ('k', testElement.getData());
}
//Test setting last element
TEST(MyListTest, testSetCharTail) {
    MyList<char> testList = {'a', 'b', 'c', 'd', 'e'};
    Element<char> *testElement;
    testList.set('m', testList.get_size() - 1);
    testElement = testList.getTail();
    EXPECT_EQ('m', testElement->getData());
}
//Test setting first element
TEST(MyListTest, testSetCharHead) {
    MyList<char> testList = {'a', 'b', 'c', 'd', 'e'};
    Element<char> *testElement;
    testList.set('*', 0);
    testElement = testList.getHead();
    EXPECT_EQ('*', testElement->getData());
}

//Testing setting wrong element
TEST(MyListTest, testSetCharNothing) {
    MyList<char> testList = {'a', 'b', 'c', 'd', 'e'};
    try {
        testList.set('6', 89);
    }
    catch (out_of_range error) {
        ASSERT_STRCASEEQ("Index is greater than list size", error.what());
    }
}
