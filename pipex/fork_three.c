#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int x = 5;
	printf("fork returned: %d\n",fork());
	x--;
	printf("This line is from child, x is %d\n", x);

	printf("%d\n",fork());
	return (0);
}

// cc fork.c && ./a.out 
// 122941 // A says (parent) I have B as child with that PID
// 122942 // A says (parent) I have C as child with that PID [or B (new parent) says I have D as child with that PID, we dont know the order]
// 0 // C says Im a child
// 122943 // B (new parent) says I have D as child with that PID
// 0 // D says Im a child
// 0 // B says I was a child 

// first fork:
//  A --> B

// second fork:
//  A --> B --> D
//  |
//  A --> C
