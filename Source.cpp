#include<iostream>
#include<string.h>
#include<string>
#include<fstream>
#include<iomanip>
#include <stdio.h>

using namespace std;
// defines a structure
struct node
{
	string state;
	int index;
	int parentindex;
	string oper;
};

node gVarState[100000];
int gVarIndex = 0;

int main()
{
	cout << endl;
	cout << setw(49) << "8 TILES PUZZLE SOLVER "<<"\n";
	for(int l=0;l<40;++l)
	{
		cout << "--";
	}
	cout<<endl<<endl;


START:
	cout << "ENTER THE PROBLEM FOR ME" << " " <<"--"<< "digits(0 to 8)" << " " << "--0 for space "<<endl;
	cin >> gVarState[0].state;
	//checks if sthe string entered contains only digits

	if (gVarState[0].state.length() != 9)
	{
		cout << "Please enter the correct state of 8 tiles puzzle"<<endl;
		goto START;
	}
	int f_check(string);
	int x;
	x = f_check(gVarState[0].state);
	if (x == 0)
	{
		cout << endl << "are you trying to fool me ...." << endl << "plz enter the correct state of 8tiles puzzle" << "\n";
		goto START;
	}
	//Checking if final state is given
	if (gVarState[0].state == "123456780")
	{
		cout << ":-) That's easy... Your problem is your solution only..." << endl;
		goto START;
	}
	//Calling Function to check the validity
	int f_check_validity(string);
	int validity = f_check_validity(gVarState[0].state);
	if (validity == 0)
	{
		cout << "Sorry !!! The solution for this problem is not possible."<<"\n";
		goto START;
	}

	int f_generate_child(node);
	void f_print_steps(node);
	gVarState[0].index = 0;
	gVarState[0].parentindex = 0;
	gVarState[0].oper = "";

	for (int i = 0; (i <= gVarIndex) && (gVarIndex<30000); ++i)
	{
		// generating child
		int j = f_generate_child(gVarState[i]);
		if (j == 1)
		{
			f_print_steps(gVarState[gVarIndex]);
			break;
		}
	}
	if (gVarIndex == 30000)
	{
		cout << "Sorry !!! This is beyond my computing power. Please provide me with some other Problem" << "\n";
		goto START;
	}
	return 0;
}
// generate child function
int f_generate_child(node lvarParentStat)
{
	string s1, s2, s3, s4, s5, s6, s7, s8, s9;
	s1 = lvarParentStat.state.at(0);
	s2 = lvarParentStat.state.at(1);
	s3 = lvarParentStat.state.at(2);
	s4 = lvarParentStat.state.at(3);
	s5 = lvarParentStat.state.at(4);
	s6 = lvarParentStat.state.at(5);
	s7 = lvarParentStat.state.at(6);
	s8 = lvarParentStat.state.at(7);
	s9 = lvarParentStat.state.at(8);
	int p[4];

	int f_calculate_priority(string);
	int f_create_node(string, string, int);
	int lvar_index = lvarParentStat.index;
	string lvar_oper[4];
	int lvar_poszero;
	int lvar_create_node;
	lvar_poszero = lvarParentStat.state.find("0") + 1;
	string s[4];
	switch (lvar_poszero)
	{
	case 1:
		//first node
		s1 = s2;
		s2 = "0";
		s[0] = "";
		s[0].append(s1); s[0].append(s2); s[0].append(s3); s[0].append(s4); s[0].append(s5); s[0].append(s6); s[0].append(s7); s[0].append(s8); s[0].append(s9);
		p[0] = f_calculate_priority(s[0]);
		lvar_oper[0] = s1 + "L";
		//second node
		s2 = s1;
		s1 = s4;
		s4 = "0";
		s[1] = "";
		s[1].append(s1); s[1].append(s2); s[1].append(s3); s[1].append(s4); s[1].append(s5); s[1].append(s6); s[1].append(s7); s[1].append(s8); s[1].append(s9);
		p[1] = f_calculate_priority(s[1]);
		lvar_oper[1] = s1 + "U";
		//third node
		s[2] = "";
		p[2] = -1;
		lvar_oper[2] = "";
		//fourth node
		s[3] = "";
		p[3] = -1;
		lvar_oper[3] = "";
		break;
	case 2:
		//creating first node
		s2 = s3;
		s3 = "0";
		s[0] = "";
		s[0].append(s1); s[0].append(s2); s[0].append(s3); s[0].append(s4); s[0].append(s5); s[0].append(s6); s[0].append(s7); s[0].append(s8); s[0].append(s9);
		p[0] = f_calculate_priority(s[0]);
		lvar_oper[0] = s2 + "L";
		//creating second node
		s[1] = "";
		s3 = s2;
		s2 = s1;
		s1 = "0";
		s[1].append(s1); s[1].append(s2); s[1].append(s3); s[1].append(s4); s[1].append(s5); s[1].append(s6); s[1].append(s7); s[1].append(s8); s[1].append(s9);
		p[1] = f_calculate_priority(s[1]);
		lvar_oper[1] = s2 + "R";

		//creating third node
		s[2] = "";
		s1 = s2;
		s2 = s5;
		s5 = "0";
		s[2].append(s1); s[2].append(s2); s[2].append(s3); s[2].append(s4); s[2].append(s5); s[2].append(s6); s[2].append(s7); s[2].append(s8); s[2].append(s9);
		p[2] = f_calculate_priority(s[2]);
		lvar_oper[2] = s2 + "U";
		//creating fourth node
		s[3] = "";
		p[3] = -1;
		lvar_oper[3] = "";
		break;

	case 3:
		//creating first node
		s3 = s2;
		s2 = "0";
		s[0] = "";
		s[0].append(s1); s[0].append(s2); s[0].append(s3); s[0].append(s4); s[0].append(s5); s[0].append(s6); s[0].append(s7); s[0].append(s8); s[0].append(s9);
		p[0] = f_calculate_priority(s[0]);
		lvar_oper[0] = s3 + "R";
		//creating second node
		s[1] = "";
		s2 = s3;
		s3 = s6;
		s6 = "0";
		s[1].append(s1); s[1].append(s2); s[1].append(s3); s[1].append(s4); s[1].append(s5); s[1].append(s6); s[1].append(s7); s[1].append(s8); s[1].append(s9);
		p[1] = f_calculate_priority(s[1]);
		lvar_oper[1] = s3 + "U";
		//creating third node
		s[2] = "";
		p[2] = -1;
		lvar_oper[2] = "";
		//creating fourth node
		s[3] = "";
		p[3] = -1;
		lvar_oper[3] = "";
		break;
	case 4:
		//creating first node
		s4 = s1;
		s1 = "0";
		s[0] = "";
		s[0].append(s1); s[0].append(s2); s[0].append(s3); s[0].append(s4); s[0].append(s5); s[0].append(s6); s[0].append(s7); s[0].append(s8); s[0].append(s9);
		p[0] = f_calculate_priority(s[0]);
		lvar_oper[0] = s4 + "D";
		//creating second node
		s[1] = "";
		s1 = s4;
		s4 = s5;
		s5 = "0";
		s[1].append(s1); s[1].append(s2); s[1].append(s3); s[1].append(s4); s[1].append(s5); s[1].append(s6); s[1].append(s7); s[1].append(s8); s[1].append(s9);
		p[1] = f_calculate_priority(s[1]);
		lvar_oper[1] = s4 + "L";
		//creating third node
		s[2] = "";
		s5 = s4;
		s4 = s7;
		s7 = "0";
		s[2].append(s1); s[2].append(s2); s[2].append(s3); s[2].append(s4); s[2].append(s5); s[2].append(s6); s[2].append(s7); s[2].append(s8); s[2].append(s9);
		p[2] = f_calculate_priority(s[2]);
		lvar_oper[2] = s4 + "U";
		//creating fourth node
		s[3] = "";
		p[3] = -1;
		lvar_oper[3] = "";
		break;
	case 5:
		//creating first node
		s5 = s2;
		s2 = "0";
		s[0] = "";
		s[0].append(s1); s[0].append(s2); s[0].append(s3); s[0].append(s4); s[0].append(s5); s[0].append(s6); s[0].append(s7); s[0].append(s8); s[0].append(s9);
		p[0] = f_calculate_priority(s[0]);
		lvar_oper[0] = s5 + "D";
		//creating second node
		s[1] = "";
		s2 = s5;
		s5 = s4;
		s4 = "0";
		s[1].append(s1); s[1].append(s2); s[1].append(s3); s[1].append(s4); s[1].append(s5); s[1].append(s6); s[1].append(s7); s[1].append(s8); s[1].append(s9);
		p[1] = f_calculate_priority(s[1]);
		lvar_oper[1] = s5 + "R";
		//creating third node
		s[2] = "";
		s4 = s5;
		s5 = s6;
		s6 = "0";
		s[2].append(s1); s[2].append(s2); s[2].append(s3); s[2].append(s4); s[2].append(s5); s[2].append(s6); s[2].append(s7); s[2].append(s8); s[2].append(s9);
		p[2] = f_calculate_priority(s[2]);
		lvar_oper[2] = s5 + "L";

		//creating fourth node
		s[3] = "";
		s6 = s5;
		s5 = s8;
		s8 = "0";
		s[3].append(s1); s[3].append(s2); s[3].append(s3); s[3].append(s4); s[3].append(s5); s[3].append(s6); s[3].append(s7); s[3].append(s8); s[3].append(s9);
		p[3] = f_calculate_priority(s[3]);
		lvar_oper[3] = s5 + "U";
		break;
	case 6:
		//creating first node
		s6 = s3;
		s3 = "0";
		s[0] = "";
		s[0].append(s1); s[0].append(s2); s[0].append(s3); s[0].append(s4); s[0].append(s5); s[0].append(s6); s[0].append(s7); s[0].append(s8); s[0].append(s9);
		p[0] = f_calculate_priority(s[0]);
		lvar_oper[0] = s6 + "D";
		//creating second node
		s[1] = "";
		s3 = s6;
		s6 = s9;
		s9 = "0";
		s[1].append(s1); s[1].append(s2); s[1].append(s3); s[1].append(s4); s[1].append(s5); s[1].append(s6); s[1].append(s7); s[1].append(s8); s[1].append(s9);
		p[1] = f_calculate_priority(s[1]);
		lvar_oper[1] = s6 + "U";
		//creating third node
		s[2] = "";
		s9 = s6;
		s6 = s5;
		s5 = "0";
		s[2].append(s1); s[2].append(s2); s[2].append(s3); s[2].append(s4); s[2].append(s5); s[2].append(s6); s[2].append(s7); s[2].append(s8); s[2].append(s9);
		p[2] = f_calculate_priority(s[2]);
		lvar_oper[2] = s6 + "R";
		//creating fourth node
		s[3] = "";
		p[3] = -1;
		lvar_oper[3] = "";
		break;
	case 7:
		//creating first node
		s7 = s4;
		s4 = "0";
		s[0] = "";
		s[0].append(s1); s[0].append(s2); s[0].append(s3); s[0].append(s4); s[0].append(s5); s[0].append(s6); s[0].append(s7); s[0].append(s8); s[0].append(s9);
		p[0] = f_calculate_priority(s[0]);
		lvar_oper[0] = s7 + "D";
		//creating second node
		s4 = s7;
		s7 = s8;
		s8 = "0";
		lvar_oper[1] = s7 + "L";
		s[1] = "";
		s[1].append(s1); s[1].append(s2); s[1].append(s3); s[1].append(s4); s[1].append(s5); s[1].append(s6); s[1].append(s7); s[1].append(s8); s[1].append(s9);
		p[1] = f_calculate_priority(s[1]);
		//creating third node
		s[2] = "";
		p[2] = -1;
		lvar_oper[2] = "";
		//creating fourth node
		s[3] = "";
		p[3] = -1;
		lvar_oper[3] = "";

		break;
	case 8:
		//creating first node
		s8 = s7;
		s7 = "0";
		s[0] = "";
		s[0].append(s1); s[0].append(s2); s[0].append(s3); s[0].append(s4); s[0].append(s5); s[0].append(s6); s[0].append(s7); s[0].append(s8); s[0].append(s9);
		p[0] = f_calculate_priority(s[0]);
		lvar_oper[0] = s8 + "R";
		//creating second node
		s7 = s8;
		s8 = s9;
		s9 = "0";
		s[1] = "";
		s[1].append(s1); s[1].append(s2); s[1].append(s3); s[1].append(s4); s[1].append(s5); s[1].append(s6); s[1].append(s7); s[1].append(s8); s[1].append(s9);
		p[1] = f_calculate_priority(s[1]);
		lvar_oper[1] = s8 + "L";
		//creating third node
		s9 = s8;
		s8 = s5;
		s5 = "0";
		s[2] = "";
		s[2].append(s1); s[2].append(s2); s[2].append(s3); s[2].append(s4); s[2].append(s5); s[2].append(s6); s[2].append(s7); s[2].append(s8); s[2].append(s9);
		p[2] = f_calculate_priority(s[2]);
		lvar_oper[2] = s8 + "D";
		//creating fourth node
		s[3] = "";
		p[3] = -1;
		lvar_oper[3] = "";

		break;
	case 9:
		//creating first node
		s9 = s6;
		s6 = "0";
		s[0] = "";
		s[0].append(s1); s[0].append(s2); s[0].append(s3); s[0].append(s4); s[0].append(s5); s[0].append(s6); s[0].append(s7); s[0].append(s8); s[0].append(s9);
		p[0] = f_calculate_priority(s[0]);
		lvar_oper[0] = s9 + "D";
		//creating second node
		s6 = s9;
		s9 = s8;
		s8 = "0";
		s[1] = "";
		s[1].append(s1); s[1].append(s2); s[1].append(s3); s[1].append(s4); s[1].append(s5); s[1].append(s6); s[1].append(s7); s[1].append(s8); s[1].append(s9);
		p[1] = f_calculate_priority(s[1]);
		lvar_oper[1] = s9 + "R";
		//creating third node
		s[2] = "";
		p[2] = -1;
		lvar_oper[2] = "";
		//creating fourth node
		s[3] = "";
		p[3] = -1;
		lvar_oper[3] = "";
		break;
	}

	int no_nodes = -1;
	int Least = p[0];
	int k = 0;
	int nextLeast = p[0];
CREATE_NEXT_LEAST:

	for (int i = 0; i < 4; i++)
	{

		if (no_nodes == 0)
		{
			if (p[i] != Least && p[i] != -1)
			{
				nextLeast = p[i];
				k = i;
				for (int z = i; z < 4; z++)
				{
					if (p[z] <= nextLeast && p[z] != Least && p[z] != -1)
					{
						nextLeast = p[z];
						k = z;
					}

				}

			}

		}
		else
		{
			if (p[i] < Least && p[i] != -1)
			{
				Least = p[i];
				k = i;
			}
		}
	}
	int j = k;
	for (int i = 0; i < 4; i++)
	{

		if (p[i] == p[j])
		{
			//create node
			lvar_create_node = f_create_node(s[i], lvar_oper[i], lvar_index);
			switch (lvar_create_node)
			{
			case 0:
			{
				no_nodes = no_nodes + 2;
				break;
			}
			case 1:
			{	return 1;
			break; }
			case 2: //Duplicate node exists
			{
				no_nodes = no_nodes+1;
				break; }
			}
		}
	}
	if (no_nodes == 0)
	{
		goto CREATE_NEXT_LEAST;
	}
	return 0;
}
// definition of function that calculates priority
int f_calculate_priority(string l_s)
{
	int k = 0;
	switch (l_s.find("1") + 1)
	{
	case 1: k = k; break;
	case 2: k = k + 1; break;
	case 3: k = k + 2; break;
	case 4: k = k + 1; break;
	case 5: k = k + 2; break;
	case 6: k = k + 3; break;
	case 7: k = k + 2; break;
	case 8: k = k + 3; break;
	case 9: k = k + 4; break;
	}
	switch (l_s.find("2") + 1)
	{
	case 1: k = k + 1; break;
	case 2: k = k; break;
	case 3: k = k + 1; break;
	case 4: k = k + 2; break;
	case 5: k = k + 1; break;
	case 6: k = k + 2; break;
	case 7: k = k + 3; break;
	case 8: k = k + 2; break;
	case 9: k = k + 3; break;
	}
	switch (l_s.find("3") + 1)
	{
	case 1: k = k + 2;   break;
	case 2: k = k + 1; break;
	case 3: k = k;     break;
	case 4: k = k + 3; break;
	case 5: k = k + 2; break;
	case 6: k = k + 1; break;
	case 7: k = k + 4; break;
	case 8: k = k + 3; break;
	case 9: k = k + 2; break;
	}
	switch (l_s.find("4") + 1)
	{
	case 1: k = k + 1; break;
	case 2: k = k + 2; break;
	case 3: k = k + 3; break;
	case 4: k = k; break;
	case 5: k = k + 1; break;
	case 6: k = k + 2; break;
	case 7: k = k + 1; break;
	case 8: k = k + 2; break;
	case 9: k = k + 3; break;
	}
	switch (l_s.find("5") + 1)
	{
	case 1: k = k + 2; break;
	case 2: k = k + 1; break;
	case 3: k = k + 2; break;
	case 4: k = k + 1; break;
	case 5: k = k; break;
	case 6: k = k + 1; break;
	case 7: k = k + 2; break;
	case 8: k = k + 1; break;
	case 9: k = k + 2; break;
	}
	switch (l_s.find("6") + 1)
	{
	case 1: k = k + 3; break;
	case 2: k = k + 2; break;
	case 3: k = k + 1; break;
	case 4: k = k + 2; break;
	case 5: k = k + 1; break;
	case 6: k = k; break;
	case 7: k = k + 3; break;
	case 8: k = k + 2; break;
	case 9: k = k + 1; break;
	}
	switch (l_s.find("7") + 1)
	{
	case 1: k = k + 2; break;
	case 2: k = k + 3; break;
	case 3: k = k + 4; break;
	case 4: k = k + 1; break;
	case 5: k = k + 2; break;
	case 6: k = k + 3; break;
	case 7: k = k; break;
	case 8: k = k + 1; break;
	case 9: k = k + 2; break;
	}
	switch (l_s.find("8") + 1)
	{
	case 1: k = k + 3; break;
	case 2: k = k + 2; break;
	case 3: k = k + 3; break;
	case 4: k = k + 2; break;
	case 5: k = k + 1; break;
	case 6: k = k + 2; break;
	case 7: k = k + 1; break;
	case 8: k = k; break;
	case 9: k = k + 1; break;
	}
	return k;
}

int f_create_node(string lvar_state, string lvar_oper, int lvar_index)
{
	for (int x = 0; x <= gVarIndex; x++)
	{
		if (lvar_state == gVarState[x].state)
			return 2;
	}
	gVarIndex = gVarIndex + 1;
	gVarState[gVarIndex].parentindex = lvar_index;
	gVarState[gVarIndex].state = lvar_state;
	gVarState[gVarIndex].oper = lvar_oper;
	gVarState[gVarIndex].index = gVarIndex;
	if (lvar_state == "123456780")
	{
		return 1;
	}
	cout << "created node - " << gVarIndex << " - " << lvar_state << " - " << lvar_index << " - " << lvar_oper << "\n";

	return 0;
}

int f_check_validity(string lvar_inputstate)
{
	/*string x = lvar_inputstate;
	int position = x.find("0");
	x.erase(x.begin() + position);
	//cout << x;
	int inv_count = 0;
	for (int q = 0; q < 8; ++q)
	{
		int max = x[q];
		for (int w = q+1; w <8; w++)
		{
			if (x[w] < x[q])
				inv_count += 1;
			else continue;

		}
	}
	//cout << inv_count;
	if (inv_count % 2 == 0)
		return 1;

	else
		return 0;*/
		return 1;


}
// definition of function that prints the steps
void f_print_steps(node lvar_finalstate)
{
	int j = lvar_finalstate.parentindex;
	int lvar_index;
	string print_steps[500];
	int no_steps = 0;
	for (int i = 0; j != 0; i++)
	{
		print_steps[i] = gVarState[j].oper;
		no_steps = i;
		lvar_index = gVarState[j].index;
		j = gVarState[lvar_index].parentindex;
	}
	//Printing Steps
	int final_steps = no_steps + 2;
	cout << "Congratulations!!! You can solve this problem in " << final_steps << " steps." << "\n";
	getchar();
	int x = 1;
	for (int i = no_steps; i >= 0; i--)
	{
		cout << "Step - "<<x<<": "<<print_steps[i] << "\n";
		x = x + 1;
	}
	cout << "Step - "<< final_steps <<": "<<lvar_finalstate.oper << "\n";
	getchar();
	for (int b = 1; b < 41; b++)
	{
		cout << "**";
	}
	cout << "\n";
	cout <<setw(42)<< "Thank You !!!"<<endl;
	for (int p = 1; p < 41;p++)
	{
		cout << "**";
	}
	cout << "\n";
	getchar();
	}
int f_check(string lvar_inputstate)
{
	string q;
	int i;
	int count = 0;
	q = lvar_inputstate;
	for (i = 0; i < 9; ++i)
	{
		if (q[i] < 57 && q[i]>47)
			count = 1;
		else count = 0;
		if (count == 0)
			return 0;
	}
	for (i = 0; i < 9; ++i)
	{
		for (int j = i + 1; j < 9; ++j)
		{
			if (q[i] != q[j])
				count = 1;
			else
				count = 0;
			if (count == 0)
				return 0;
		}


	}
	return 1;
}
