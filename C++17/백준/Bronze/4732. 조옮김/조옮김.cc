#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

string line;
int amount;
string sounds[] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};

unordered_map<string, string> soundMap = {
    {"Bb", "A#"},
    {"Cb", "B"},
    {"B#", "C"},
    {"Db", "C#"},
    {"Eb", "D#"},
    {"Fb", "E"},
    {"E#", "F"},
    {"Gb", "F#"},
    {"Ab", "G#"}};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (true)
    {
        getline(cin, line);

        if (line == "***")
        {
            break;
        }

        cin >> amount;
        cin.ignore();

        stringstream ss = stringstream(line);
        string word;

        while (ss >> word)
        {
            if (soundMap.find(word) != soundMap.end())
            {
                word = soundMap[word];
            }

            auto it = find(begin(sounds), end(sounds), word);
            int idx = distance(begin(sounds), it);

            idx = (idx + amount + 12) % 12;

            cout << sounds[idx] << " ";
        }
        cout << "\n";
    }
    return 0;
}