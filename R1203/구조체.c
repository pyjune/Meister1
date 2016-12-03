#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct memberStruct{
	char name[20];
	int age;
	char phone[20];
};

typedef struct{
	char name[20];
	int age;
	char phone[20];
}memberType;
void printMember(memberType member);
void printMember2(memberType *pMember);


int main(int argc, char *argv[]) {
	struct memberStruct member1 = {"pyjune", 40, "010-2263-3621"};
	struct memberStruct member3;
	memberType member2= {"pyjune", 40, "010-2263-3621"};
	
	printf("%s, %d, %s\n", member1.name, member1.age, member1.phone);
	member3 = member1;
	printf("%s, %d, %s\n", member3.name, member3.age, member3.phone);
	strcpy(member3.name, "로봇");
	printf("%s\n", member3.name);
	printMember(member2);
	printMember2(&member2);
	return 0;
}
void printMember2(memberType *pMember)
{
	printf("%s, %d, %s\n", pMember->name, pMember->age, pMember->phone);
}
void printMember(memberType member)
{
	printf("%s, %d, %s\n", member.name, member.age, member.phone);
}
