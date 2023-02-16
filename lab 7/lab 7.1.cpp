#include <stdio.h>
#include <string.h>

struct studentNode {
	char name[20];
	int age;
	char sex;
	float gpa;
struct studentNode *next;
};


class LinkedList {
protected:
	struct studentNode *start, **now;
public:
	LinkedList() { start = NULL; now = &start; }
	~LinkedList() {
		while (start) {
		DelNode();
		}
	}
void InsNode(char n[], int a, char s, float g) {
	struct studentNode *temp = new studentNode;
	strcpy(temp->name, n);
	temp->age = a;
	temp->sex = s;
	temp->gpa = g;
	temp->next = start;
	start = temp;
	now = &start;
}
void DelNode() {
	struct studentNode *temp = start;
	start = start->next;
	delete temp;
}
void GoNext() {
	if (*now) {
	now = &((*now)->next);
	}
}
virtual void ShowNode() {
		if (*now) {
			printf("Name: %s\n", (*now)->name);
			printf("Age: %d\n", (*now)->age);
			printf("Sex: %c\n", (*now)->sex);
			printf("GPA: %.1f\n", (*now)->gpa);
		}
	}
};

class NewList : public LinkedList {
	public:
	void GoFirst() { now = &start; }
	virtual void ShowNode() {
		GoFirst();
		while (*now) {
			printf("Name: %s\n", (*now)->name);
			printf("Age: %d\n", (*now)->age);
			printf("Sex: %c\n", (*now)->sex);
			printf("GPA: %.1f\n", (*now)->gpa);
			GoNext();
		}
	}
};

int main() {
LinkedList listA;
NewList listB;
LinkedList *listC;

listA.InsNode("one", 1, 'A', 1.1);
listA.InsNode("two", 2, 'B', 2.2);
listA.InsNode("three", 3, 'C', 3.3);
listA.GoNext();
listA.ShowNode();

listB.InsNode("four", 4, 'D', 4.4);
listB.InsNode("five", 5, 'E', 5.5);
listB.InsNode("six", 6, 'F', 6.6);
listB.GoNext();
listB.DelNode();
listB.ShowNode();

listC = &listA;
listC->GoNext();
listC->ShowNode();

listC = &listB;
listC->ShowNode();

return 0;
}
