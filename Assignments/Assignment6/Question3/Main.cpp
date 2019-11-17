
#include <vector>
#include <time.h>
#include "PersonComp.h"
#include "Priority_Queue.h"




int main()
{
	vector<string> names = { "Abby", "Bonnie", "Claire", "Delores", "Emily", "Frida",
		"Gail", "Helen", "Iris", "Jenny", "Kelly", "Lisa", "Molly", "Nancy", "Olivia",
		"Paula", "Quinn", "Ruby", "Sara", "Tricia", "Uma", "Victoria", "Wendy", "Xena",
		"Yasmin", "Zoe" };
	
	priority_queue<Person, PersonComp> The_Q;

	srand(time(NULL));
	Person p1(names.at(0), rand() % 6);
	Person p2(names.at(1), rand() % 6);
	Person p3(names.at(2), rand() % 6);
	Person p4(names.at(3), rand() % 6);
	Person p5(names.at(4), rand() % 6);
	Person p6(names.at(5), rand() % 6);
	Person p7(names.at(6), rand() % 6);
	Person p8(names.at(7), rand() % 6);
	Person p9(names.at(8), rand() % 6);
	Person p10(names.at(9), rand() % 6);
	Person p11(names.at(10), rand() % 6);
	Person p12(names.at(11), rand() % 6);
	Person p13(names.at(12), rand() % 6);
	Person p14(names.at(13), rand() % 6);
	Person p15(names.at(14), rand() % 6);
	Person p16(names.at(15), rand() % 6);
	Person p17(names.at(16), rand() % 6);
	Person p18(names.at(17), rand() % 6);
	Person p19(names.at(18), rand() % 6);
	Person p20(names.at(19), rand() % 6);
	Person p21(names.at(20), rand() % 6);
	Person p22(names.at(21), rand() % 6);
	Person p23(names.at(22), rand() % 6);
	Person p24(names.at(23), rand() % 6);
	Person p25(names.at(24), rand() % 6);
	Person p26(names.at(25), rand() % 6);

	The_Q.push(p1);
	The_Q.push(p2);
	The_Q.push(p3);
	The_Q.push(p4);
	The_Q.push(p5);
	The_Q.push(p6);
	The_Q.push(p7);
	The_Q.push(p8);
	The_Q.push(p9);
	The_Q.push(p10);
	The_Q.push(p11);
	The_Q.push(p12);
	The_Q.push(p13);
	The_Q.push(p14);
	The_Q.push(p15);
	The_Q.push(p16);
	The_Q.push(p17);
	The_Q.push(p18);
	The_Q.push(p19);
	The_Q.push(p20);
	The_Q.push(p22);
	The_Q.push(p23);
	The_Q.push(p24);
	The_Q.push(p25);
	The_Q.push(p26);

	return 0;
}
