#include <bits/stdc++.h>
using namespace std;

class CountMinSketch {
private:
  int width;
  vector<vector<int>> table;

  int hash1(string &s) const {
    int val = 0;
    for (char c : s) {
      val = (val * 31 + c) % width;
    }
    return abs(val);
  }

  int hash2(string &s) const {
    int val = 0;
    for (char c : s) {
      val = (val * 37 + c) % width;
    }
    return abs(val);
  }

  int hash3(string &s) const {
    int val = 0;
    for (char c : s) {
      val = (val * 41 + c) % width;
    }
    return abs(val);
  }

  string toLower(string &s) const {
    string res = s;
    transform(res.begin(), res.end(), res.begin(), ::tolower);
    return res;
  }

public:
  CountMinSketch(int w) : width(w) {
    table = vector<vector<int>>(3, vector<int>(width, 0));
  }

  void update(string &item) {
    string word = toLower(item);
    int h1 = hash1(word);
    int h2 = hash2(word);
    int h3 = hash3(word);

    table[0][h1]++;
    table[1][h2]++;
    table[2][h3]++;
  }

  int evaluate(string &item) {
    string word = toLower(item);
    int h1 = hash1(word);
    int h2 = hash2(word);
    int h3 = hash3(word);

    cout << "Hash positions for '" << item << "':" << endl;
    cout << "h1: " << h1 << " (value: " << table[0][h1] << ")" << endl;
    cout << "h2: " << h2 << " (value: " << table[1][h2] << ")" << endl;
    cout << "h3: " << h3 << " (value: " << table[2][h3] << ")" << endl;

    return min({table[0][h1], table[1][h2], table[2][h3]});
  }

  void printTable() {
    cout << "Count-Min Sketch Table:" << endl;
    for (int i = 0; i < 3; i++) {
      cout << "Row " << i << ": ";
      for (int j = 0; j < width; j++) {
        cout << table[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  vector<string> input = {"Shubham", "test", "Shubham",
                          "hash",    "test", "Shubham"};
  int width = 10;

  CountMinSketch cms(width);
  cout << "Inserting items into Count-Min Sketch..." << endl;
  for (const string &item : input) {
    cms.update(item);
  }

  cms.printTable();

  cout << "Frequency estimates:" << endl;
  cout << "Shubham: " << cms.evaluate("Shubham") << endl;
  cout << "example: " << cms.evaluate("example") << endl;
  cout << "test: " << cms.evaluate("test") << endl;
  cout << "hash: " << cms.evaluate("hash") << endl;

  return 0;
}
