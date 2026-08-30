class Solution {
public:
    int compress(vector<char>& chars) {
         int n = chars.size();
    int read = 0;
    int write = 0;
    while (read< n) {
        char currChar = chars[read];
        int count = 0;
        while (read<n && currChar==chars[read]) {
            count++;
            read++;
        }
        chars[write] =currChar;
        write++;
        if (count>1) {
            string c = to_string(count);
            for (char ch: c) {
                chars[write] = ch;
                write++;
            }
        }
    }
    return write;
    }
};