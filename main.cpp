
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <memory>

#include "SqlConnection.h"
#include "DbConnection.h"
#include "OracleConnection.h"
#include "DbCommand.h"
#include "PlayerPoolCommand.h"

/*
Write a function template called concat() with two template type parameters
and two function parameters t1 and t2. The function first converts t1 and t2 to a string and
then returns the concatenation of those two strings. For this exercise, focus only on numerical
input like integers and floating-point numbers for which std::to_string() is supported.
Create and use a proper concept to make sure users of the function template don’t try to use
it with unsupported types. Try to write your function template without using the
template keyword.
*/
template <typename T> 
concept ConvertibleToString = requires (T a) {std::to_string(a);};
std::string ConCat(const ConvertibleToString auto& pre,const ConvertibleToString auto& post)
{
    return std::to_string(pre) + std::to_string(post);

}

/*
 We can access the elements of an array randomly using an index. An array,
however, is not permanent. When the program terminates, the contents of the array are destroyed. 
We can simulate an array with a binary file using random access. Create two programs. 
In the first program, store 10 different double values in a file. 
In the second program, randomly retrieve some of the values stored in the file by the first program. 
Note that we use two application programs to show that after the first program terminates, 
the file exists and can be accessed by the second program.
*/
void WriteArray()
{
    std::ofstream file("data.dat",std::ios::binary | std::ios::out);
    if(!file.is_open())
        return;
    
    std::vector<double> vec{0.0,1.0,2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
   
    for(int i = 9; i >= 0; i--)
    {
        file.write(reinterpret_cast<const char*>(&vec[i]),sizeof(double));
    }
    
    file.close();
}
void ReadArray()
{
    std::ifstream file("data.dat",std::ios::binary | std::ios::in | std::ios::ate);

    if(!file.is_open())
        return;

    int max = file.tellg()/ sizeof(double);

    int input{};

    std::string prompt{"Please enter a position to read the number, or -1 to exit: "};
    std::cout << prompt;
    std::cin >> input;

    while(input != -1 && input >= 0 && input < max )
    {

        file.seekg(sizeof(double) * input,std::ios::beg);

        double d{};
        file.read(reinterpret_cast<char*>(&d),sizeof(double));

        std::cout << d << " \n";

        std::cout << prompt;
        std::cin >> input;
    }

    file.close();

}

/*
Write a program that prompts the user to input a string. 
The program then uses the function substr to remove all the vowels from the string. 
For example, if str = "There", then after removing all the vowels, str = "Thr". 
After removing all the vowels, output the string. 
Your program must contain a function to remove all the vowels 
and a function to determine whether a character is a vowel.
*/
/*
char vowels[]{'a','e','i','o','u'};
bool IsVowel(const char& letter)
{
    char c = std::tolower(letter);
    for(size_t i = 0; i < std::size(vowels); i++)
        if(c == vowels[i])
            return true;
    return false;
    
}
void RemoveVowels()
{
    std::string prompt{"Please enter a string: "};
    std::cout << prompt;

    std::string input{};
    std::getline(std::cin,input);

    size_t i{0};
    std::string s;

    while(i < input.length())
    {
        if(IsVowel(input[i]))
        {
           input = input.substr(0,i) + input.substr(i + 1, std::string::npos);
        }
        else
            i++;
    }

    std::cout << input;
}




class SmartPointer
{
    public:
        explicit SmartPointer(int* ptr): ptr{ptr}{}
        ~SmartPointer(){ if(ptr) delete ptr; ptr = nullptr;}
    private:
        int* ptr{nullptr};
};
void Merge(std::vector<int>& vec, const std::vector<int>& left, const std::vector<int>& right);

void MergeSort(std::vector<int>& vec)
{

    if(vec.size() < 2)
        return;


    int mid = vec.size() / 2;

    //split the array into two halves down the middle
    std::vector<int> leftArr{vec.begin(), vec.begin() + mid};
    std::vector<int> rightArr{vec.begin() + mid, vec.end()};

    //divide the two arrays
    MergeSort(leftArr);
    MergeSort(rightArr);

    //merge the two arrays again
    Merge(vec, leftArr, rightArr);
}

void Merge(std::vector<int>& vec, const std::vector<int>& left, const std::vector<int>& right)
{
    int posK        = 0;
    int leftPtr     = 0;
    int rightPtr    = 0;

    //loop through two arrays, put smallest number in vec
    while(leftPtr < std::size(left) && rightPtr < std::size(right))
    {
        if(left[leftPtr] <= right[rightPtr])
        {
            vec[posK++] = left[leftPtr++];
        }
        else
        {
            vec[posK++] = right[rightPtr++];
        }
    }

    //add any remaining elements in left to end of vec
    while(leftPtr < std::size(left))
    {
        vec[posK++] = left[leftPtr++];
    }

    //add any remaining elements in right to end of vec
    while(rightPtr < std::size(right))
    {
        vec[posK++] = right[rightPtr++];
    }
}


void QuickSort(std::vector<int>& vec, int start, int end)
{

    if(start >= end)
        return;

    
    int pivot = vec[end - 1];

    int leftBarrier = start - 1;;

    for(int i = start; i < end; i++)
    {
        std::cout << "Pivot :" << pivot << " Vec[i] :" << vec[i] << std::endl;
        if(pivot > vec[i])
        {
            leftBarrier++;
            std::swap(vec[i], vec[leftBarrier]);
            std::cout <<"Swapping: " "Pivot :" << pivot 
                      << " Vec[leftbarrier] :" << vec[leftBarrier] << std::endl;
        }
    }


        leftBarrier++;
        std::swap(vec[leftBarrier], vec[end - 1]);
    

    int mid = (start + end) / 2;

    QuickSort(vec, 0, mid);
    QuickSort(vec,mid + 1, end -  start);


}

void QuickSort(std::vector<int>& vec)
{
    QuickSort(vec, 0, std::size(vec));
}*/

int main(int argc, char* argv[])
{

    std::shared_ptr<DbConnection> connect;
    connect = std::make_shared<OracleConnection>("Player Database");
    connect->OpenConnection();
    connect->CloseConnection();

    std::unique_ptr<DbCommand> cmd;
    cmd = std::make_unique<PlayerPoolCommand>(connect, "Clear the Pool");
    cmd->Execute();


    
    return 0;
}