#include <cstdio>
#include <queue>
 
using namespace std;
 
const int MAX_SIZE = 2e5 + 5;
 
int numElements, divider;
int dataArray[MAX_SIZE];
long long resultSum;
 
void processData() {
    scanf("%d%d", &numElements, &divider);
    resultSum = 0;
    priority_queue<int> maxHeap;
    for (int index = 1; index <= numElements; index++) {
        scanf("%d", &dataArray[index]);
        maxHeap.push(dataArray[index]);
        if ((numElements - index + 1) % (divider + 1) == 0) {
            resultSum += maxHeap.top();
            maxHeap.pop();
        }
    }
    printf("%lld
", resultSum);
}
 
int main() {
    int testCases;
    scanf("%d", &testCases);
    while (testCases--)
        processData();
    return 0;
}