#include <iostream>
#include <stdexcept>
#include <limits>
#include <array>
#include <cctype>
#include <iomanip>
/*
(Packing Characters into Unsigned Integers) The left-shift operator can be used to pack four
character values into a four-byte unsigned integer variable. Write a program that inputs four
characters from the keyboard and passes them to function packCharacters. To pack four characters into an
unsigned integer variable, assign the first character to the unsigned variable,
shift the unsigned variable left by eight bit positions and combine the unsigned variable with the
second character using the bitwise inclusive-OR operator, etc.The program should output the characters
in their bit format before and after they’re packed into the unsigned integer to prove that
they’re in fact packed correctly in the unsigned variable
*/

/*
2. (Unpacking Characters from Unsigned Integers) Using
the right-shift operator, the bitwise AND operator and a mask, write function
unpackCharacters that takes the unsigned integer from Exercise 22.8 and unpacks it into four characters.
To unpack characters from an unsigned four-byte integer, combine pow the unsigned integer with a mask
and right-shift the result. To create the masks you’ll need to unpack the four characters, left- shift
the value 255 in the mask variable by eight bits 0, 1, 2 or 3 times (depending on the byte you are
unpacking). Then take the combined result each time and right shift it by eight bits the same number of
times. Assign each resulting value to a char variable. The program should print the unsigned integer in
bits before it’s unpacked, then print the characters in bits to confirm that they were unpacked correctly.

*/

const int CHARCOUNT{4};
void PrintBits(unsigned int number)
{
    int mask{1};
    std::string output{};
    
    for (size_t i = 0; i < 32; i++)
    {
        if (number & (mask << i))
        {
            output = "1" + output;
        }
        else
            output = "0" + output;

        if ((i + 1) % 4 == 0)
            output = " " + output;
    }
    std::cout << std::setw(50) << std::left << output;
}
unsigned int PackCharacters(std::array<char, CHARCOUNT> arr)
{
    unsigned int packedInt{};

    std::cout << "Packing Characters: \n";

    for (size_t i = 0; i < CHARCOUNT; i++)
    {
        std::cout << std::setw(15) << std::left
                  << "Char value: " << arr[i];

        PrintBits(static_cast<unsigned int>(arr[i]));

        std::cout << std::endl;
        // shift the number over one byte and put letter in last byte
        packedInt = (packedInt << (8)) | arr[i];

        std::cout << std::setw(16) << std::left
                  << "Integer value: ";

        PrintBits(packedInt);
        std::cout << std::endl;
    }
    std::cout << "Finished Packing Characters.\n";
    return packedInt;
}
void UnPackCharacters(unsigned int number, std::array<char, CHARCOUNT> &arr)
{
    int mask{0x000000FF};
    std::cout << "Unpacking Characters: \n"
              << "Char values: ";
    for (size_t i = 0, shift = arr.size() - 1; i < arr.size(); i++)
    {
        // shift the number over to the last byte
        // and then and it with the mask.
        arr[i] = (number >> (((shift - i) * 8)) & mask);
        std::cout << arr[i] << " ";
    }
    std::cout << "\nFinished Unpacking Characters." 
              << std::endl;
}
void Run()
{
    std::array<char, CHARCOUNT> arr{};
    std::string prompt{"Please enter 4 alphabet characters to pack and then enter to finish."};

    int count = 0;
    std::cout << prompt << std::endl;
    for (auto it = std::begin(arr); it != std::end(arr);)
    {
        std::cin >> (*it);
        // if input is successful, continue
        if (std::cin.good() && std::isalpha((*it)))
        {
            it++;
            count++;
        }
        else
        {
        //on input failure, reset input integrity and clear the buffer
            std::cin.clear();
            std::string output{};
            std::cin >> output;
            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "WARNING: Bad Input encountered: " << *it << output << std::endl;
            std::cout << "Please enter " << CHARCOUNT - count << " more alphabet"
                      << " characters and then press enter." << std::endl;
        }
    }

    unsigned int num = PackCharacters(arr);

    std::array<char, CHARCOUNT> arr2;

    UnPackCharacters(num, arr2);

}





int main(int argc, char *argv[])
{

    Run();

    return 0;
}