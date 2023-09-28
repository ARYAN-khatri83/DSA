vector<string> printNTimes() {
	// Write your code her

void printNTimes(int n) {
    if (n <= 0) {
        return;
    }

    cout << "Coding Ninjas ";
    printNTimes(n - 1);
}

int main() {
    int n;
    cin >> n;

    printNTimes(n);

    return 0;
}
