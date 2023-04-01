# File Type

Created: October 24, 2022 12:09 PM
Created By: Yezhi Wu
Last Edited By: Xin Chen
Last Edited Time: November 3, 2022 4:11 PM
Status: In Progress
Type: Coding

# ConvertToString

```cpp

// string convertToString(string* array,string replacer,  int size)
int size = 7;
string arrays[size] = {"a1", "a2", "a3", "a4", "a5", "a6", "a7"};

string str = convertToString(array, ";", size); 
str; // "a1;a2;a3;a4;a5;a6;a7"

string str = convertToString(array, ",", size); 
str; // "a1,a2,a3,a4,a5,a6,a7"
```

# ConvertToArray

```cpp

// convertToArray(string covertStr, string replacer, int size)
int size = 7;
string str = "a1;a2;a3;a4;a5;a6;a7";
srting *array = convertToArray(str,";",size);
// *array// {"a1", "a2", "a3", "a4", "a5", "a6", "a7"}

string str = "a1,a2,a3,a4,a5,a6,a7";
srting *array = convertToArray(str,",",size);
// *array// {"a1", "a2", "a3", "a4", "a5", "a6", "a7"}
```