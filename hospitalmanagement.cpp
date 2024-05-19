#include <iostream>
#include <string.h>
using namespace std;
struct doctors
{
	char name[100];
	char speciality[100];
	double fees;
};
struct doctors doc[15];
int doc_choice;
int COUNT_S=0,COUNT_D=0;
struct Pat
{
	char name[20];
	char mobNo[10];
	string patientId;
	string doc_name;
	struct Pat *next; 
};
struct Pat *head1 = NULL,*head2 = NULL;
void insert(char n[],char mNo[],string pId,int ch)
{
	
		struct Pat *newNode=new struct Pat;
		strcpy(newNode->name,n);
		strcpy(newNode->mobNo,mNo);
		newNode->patientId = pId;
		newNode->doc_name = doc[doc_choice-1].name;
	
		newNode->next=NULL;
	
		struct Pat *temp = NULL;
		if(ch==1)
		{
			temp = head1;
			if(head1==NULL)
				head1=newNode;
		}
		else
		{
			temp = head2;
			if(head2==NULL)
				head2=newNode;
		}
		
		if(temp!=NULL)
		{	
			while(temp->next!=NULL)
	  			temp=temp->next;
			temp->next=newNode;
		}
}

void display(int ch)
{
	struct Pat *temp = NULL;
	if(ch==1) temp = head1;
	else if(ch==2) temp= head2;	
	cout<<"PATIENT NAME\tMOBILE NUMBER\tPATIENT ID\tDOCTOR NAME"<<endl;
	while(temp->next!=NULL)
	{
		cout<<temp->name<<"\t";
		cout<<temp->mobNo<<"\t";
		cout<<temp->patientId<<"\t";
		cout<<temp->doc_name<<"\t"<<endl;
		temp=temp->next;
		cout<<""<<endl;
	}
	cout<<temp->name<<"\t";
	cout<<temp->mobNo<<"\t";
	cout<<temp->patientId<<"\t";
	cout<<temp->doc_name<<"\t"<<endl;
}

void del(string pId,int ch)//Harsh
{
	int flag=0;	
	struct Pat *temp_del;
	if(ch==1) 
	{
		temp_del = head1;
		if(temp_del->patientId==pId)
		{
			head1=head1->next;
			flag=1;
		}
	}
	else if(ch=2) 
	{
		temp_del = head2;
		if(temp_del->patientId==pId)
		{
			head2=head2->next;
			flag=1;
		}
	}
	
	
	else if(temp_del->patientId!=pId)
	{
	
	while(temp_del->next!=NULL)
	{
		if(temp_del->next->patientId==pId)
		{
			temp_del->next=temp_del->next->next;
			flag=1;
		}
		else
			temp_del=temp_del->next;
	}
	}
	if(flag==0)
	cout<<"Element not found"<<endl;
	
}

void billCalculation(struct Pat *temp_yes)
{
	int tenure;
	cout<<"ENTER HIS STAY IN THE HOSPITAL(IN DAYS) : "<<endl;
	cin>>tenure;
	cout<<"\n\n\n===========================BILL DETAILS=============================\n\n"<<endl;
	//cout<<"\n-----------PATIENT DETAILS----------"<<endl;
	cout<<"Patient ID : "<<temp_yes->patientId<<endl;
	cout<<"NAME : "<<temp_yes->name<<endl;
	cout<<"Mobile Number : "<<temp_yes->mobNo<<endl;
	cout<<"Incharge Doctor : "<<temp_yes->doc_name<<endl;
    cout<<"\n-----------------------COST DETAILS--------------------"<<endl;
	cout<<"HOSPITAL FEES : "<<(8000*tenure)<<"\n"<<endl;
	cout<<"MEDICAL FEES : "<<(500*tenure)<<"\n"<<endl;
	for(int i=0;i<15;i++)
	{
		if(temp_yes->doc_name == doc[i].name)
		{ 
			cout<<"DOCTOR FEES : "<<(doc[i].fees * tenure)<<"\n"<<endl;
			cout<<"TAX PAYABLE : "<<0.05*((8000*tenure)+(500*tenure)+(doc[i].fees*tenure))<<endl;
			cout<<"--------------------------------------------------------------"<<endl;
			cout<<"TOTAL FEES : "<<1.05*((8000*tenure)+(500*tenure)+(doc[i].fees*tenure))<<endl;
			cout<<"--------------------------------------------------------------"<<endl;
			break;
		}
	}

	
						
		  			    
}

void doctors_name()
{
	
	cout<<"\n\n-------------------------------LIST OF DOCTORS-----------------------------\n"<<endl;
	cout<<"DOCTOR'S NAME\t\t       DEPARTMENT \t VISITING FEES(In Rs.)"<<endl;
	strcpy(doc[0].name,"Dr.Girish Menon");
	strcpy(doc[0].speciality,"Neurology Dept.    ");
	doc[0].fees = 500.0;
	
	strcpy(doc[1].name,"Dr.Abdul Razak");
	strcpy(doc[1].speciality,"Cardiology Dept.");
	doc[1].fees = 1500.0;
	
	strcpy(doc[2].name,"Dr.Anupam Choudhary");
	strcpy(doc[2].speciality,"Urology Dept.      ");
	doc[2].fees = 200.0;
	
	strcpy(doc[3].name,"Dr.Akhila Vasudeva");
	strcpy(doc[3].speciality,"Gynaecology Dept.");
	doc[3].fees =1200.0;
	
	strcpy(doc[4].name,"Dr.Amrath Raj BK");
	strcpy(doc[4].speciality,"Orthopaedics Dept.");
	doc[4].fees = 1000.0;
	
	
	strcpy(doc[5].name,"Dr.Juanitha George");
	strcpy(doc[5].speciality,"Paediatrics Dept.");
	doc[5].fees = 750.0;
	
	strcpy(doc[6].name,"Dr.Chidanand Shetty");
	strcpy(doc[6].speciality,"Opthalmology Dept.");
	doc[6].fees = 250.0;

	strcpy(doc[7].name,"Dr.Deeksha Pandey");
	strcpy(doc[7].speciality,"Gynaecology Dept.");
	doc[7].fees = 1250.0;
	
	strcpy(doc[8].name,"Dr.Mahesh Kulkarni");
	strcpy(doc[8].speciality,"Orthopaedics Dept.");
	doc[8].fees = 900.0;
	
	strcpy(doc[9].name,"Dr.Praveen Samuel");
	strcpy(doc[9].speciality,"Paediatrics Dept.");
	doc[9].fees = 700.0;

	strcpy(doc[10].name,"Dr.Ganesh Pai C");
	strcpy(doc[10].speciality,"Gastroenterology Dept.");
	doc[10].fees = 975.0;
	
	strcpy(doc[11].name,"Dr.Shiran Shetty");
	strcpy(doc[11].speciality,"Gastroenterology Dept.");
	doc[11].fees = 1075.0;
	
	strcpy(doc[12].name,"Dr.Darshan Ranga");
	strcpy(doc[12].speciality,"Nephrology Dept.");
	doc[12].fees = 1575.0;
	
	strcpy(doc[13].name,"Dr.Mohan Bhojaraja");
	strcpy(doc[13].speciality,"Nephrology Dept.");
	doc[13].fees = 1975.0;
	
	strcpy(doc[14].name,"Dr.Vijaya Pai");
	strcpy(doc[14].speciality,"Opthalmology Dept.");
	doc[14].fees = 235.0;
	cout<<"---------------------------------------------------------------------------"<<endl;
	int i;
	for(i=0;i<15;i++)
	{
		cout<<(i+1)<<") "<<doc[i].name<<"\t\t"<<doc[i].speciality<<"\t\t"<<doc[i].fees<<"\n";
	}
	cout<<"---------------------------------------------------------------------------"<<endl;
}
int mob_Check(char mobNo[])
{
	int c=0,f=1;
	
	for(int i=0;mobNo[c]!='\0';i++)
	{
		if(mobNo[i]<'0' || mobNo[i]>'9')
		{	
			f=0;
			return 0;
		}
		else if(mobNo[i]>='0' && mobNo[i]<='9')
		{
			//cout<<"x ";
			c++;
		}			
	}
	//cout<<"Number of Digits : "<<c<<endl;
	if(f==1 && c==10)
		return 1;
	else 
		return 0;
}

void sort(int ch)
{
 	struct Pat  *i ;
	if(ch==1) i = head1;
	else if(ch==2) i = head2;
	
 	while(i->next!=NULL)
	{
		struct Pat  *ptr = i;
		struct Pat  *j = i->next;
		
		while(j->next!=NULL)
		{
		
			if(strcmp(i->name,j->name)>0)
			{
			
				ptr = j;
			}
			j=j->next;
		}
		
		if(strcmp(i->name,j->name)>0) ptr=j;
		
		char n[20];
		strcpy(n,i->name);
		strcpy(i->name,ptr->name);
		strcpy(ptr->name,n);
		
		char mN[10];
		strcpy(mN,i->mobNo);
		strcpy(i->mobNo,ptr->mobNo);
		strcpy(ptr->mobNo,mN);
					
		string p;
		p = i->patientId;
		i->patientId = ptr->patientId;
		ptr->patientId = p;	
					
		string d;
		d = i->doc_name;
		i->doc_name = ptr->doc_name;
		ptr->doc_name = d;
		
		i=i->next;
	}
	if(ch==1) display(1);
	else if(ch==2) display(2);
	
}

int s_search(string pId,int ch)
{	
	int flag=0;
	struct Pat *temp= NULL;
	if(ch==1)
	 	temp = head1;
	else if(ch==2)
	 	temp = head2;
	if((COUNT_S>0 && ch==1) || (COUNT_D>0 && ch==2))
	{
	if(temp->patientId==pId)
	{
		flag=1;
	}
	else
	{
		while(temp->next!=NULL)
		{
			if(temp->next->patientId==pId)
			{
				flag = 1;
				break;
			}
			else
				temp=temp->next;
		}
	}
	}
	return flag;
}

int main()
{
	int choice;
	cout<<"---------------WELCOME TO KASTURBA MEDICAL HOSPITAL---------------"<<endl;
	
	do
	{
	
	cout<<"   <1>PATIENT INTERFACE\n   <2>STAFF INTERFACE\n   <3>EXIT"<<endl;
	cout<<"ENTER CHOICE : ";
	cin>>choice;
	char name[20],last[20];
	string patientId;
	char mobNo[10];
	
	if(choice==1)
	{
		
		cout<<"Enter your first name : ";
		cin>>name;
		cout<<"Enter your last name : ";
		cin>>last;
		strcat(name," ");
		strcpy(name,strcat(name,last));
		for(int i=0;name[i]!='\0';i++)
		{
			if(name[i]>='a' && name[i]<='z')
				name[i]-=32;
		}
	
		
		do
		{
		cout<<"Enter your mobile number : ";
		cin>>mobNo;
		if(mob_Check(mobNo)==0)
				cout<<"Invalid Mobile Number"<<endl;
		else break;
		}while(mob_Check(mobNo)==0);
		
		
		//fflush(stdin);
		do
		{
		cout<<"Enter the 4digit PatientID alloted to you : ";
		cin>>patientId;
			if(patientId.length()!=4 || s_search(patientId,1)==1 || s_search(patientId,2)==1)
				cout<<"Invalid Patient ID : "<<endl;
		}while(patientId.length()!=4 || s_search(patientId,1)==1 || s_search(patientId,2)==1);
		
		doctors_name();
		
		do
		{
		
		cout<<"INPUT THE CORRESPONDING NUMBER TO REFER TO THAT DOCTOR : ";
		cin>>doc_choice;
		if(doc_choice<=0 || doc_choice>15)
			cout<<"NO SUCH DOCTOR AVAILABLE"<<endl;
		}while(doc_choice<=0 || doc_choice>15);
		
		int choose;
		cout<<"\nTYPES OF BEDS : \n   1.SINGLE OCCUPANCY\tRs.8000/day\n   2.DOUBLE OCCUPANCY\tRs.5000/day\n   3.GENERAL CHECKUP"<<endl;
		cout<<"\nEnter your preference : ";
		cin>>choose;
		
	
		switch(choose)
		{
			case 1:	if(COUNT_S==5)
					{
						cout<<"SORRY FOR THE INCOVENIENCE, THERE ARE NO MORE SINGLE OCCUPANCY BEDS AVAILABLE.\nYOU WILL BE ALLOTED DOUBLE OCCUPANCY"<<endl;
						//cout<<COUNT_S;
						
						insert(name,mobNo,patientId,2);
						COUNT_D++;
						choose=2;	
					}
					else
					{
						if(choose!=2)
							COUNT_S++;
						insert(name,mobNo,patientId,1);
						cout<<"YOU ARE SUCCESSFULLY ADMITTED"<<endl;
					}
					break;
			case 2: COUNT_D++;
					insert(name,mobNo,patientId,2);
					cout<<"YOU ARE SUCCESSFULLY ADMITTED"<<endl;
					break;
			case 3: cout<<"-------GENERAL CHECKUP DETAILS------"<<endl;
					cout<<"   Patient ID : "<<patientId<<endl;
					cout<<"   NAME : "<<name<<endl;
					cout<<"   Mobile Number : "<<mobNo<<endl;
					cout<<"   Incharge Doctor : "<<doc[doc_choice-1].name<<endl;
    				cout<<"   DOCTOR FEES : "<<doc[doc_choice-1].fees<<endl;
    				cout<<"------------------------------------"<<endl;
							
					break;	
		    default: cout<<"INVALID OUTPUT"<<endl;
					 break;
			
		}
	}
	else if(choice==2)
	{
		int ch;
		do
		{
		cout<<"   <1>SINGLE OCCUPANCY DATA\n   <2>DOUBLE OCCUPANCY DATA\n   <3>EXIT"<<endl;
		cout<<"Enter choice : ";
		cin>>ch;
		if(ch==1)
		{
			cout<<"************************SINGLE OCCUPANCY BED LIST**********************"<<endl;
			
			if(COUNT_S==0)
				cout<<"\n********CURRENTLY THERE ARE NO ENTRIES TO DISPLAY IN SINGLE OCCUPANCY**********\n\n";
			else
			{
				//display_Single();
				sort(1);
				cout<<"\nAVAILABLE SEATS : "<<(5-COUNT_S)<<endl;
			char yn;
			cout<<"IS THERE A PATIENT TO BE DISCHARGED?\n\nENTER Y FOR YES OR ANYTHING ELSE TO QUIT : "<<endl;
			cin>>yn;
			
			if(yn=='Y' || yn=='y')
			{
				string discharge;
				cout<<"ENTER PATIENT ID"<<endl;
				cin>>discharge;
				
				int found=0;
				struct Pat *temp_yes = head1; 
				
				while(temp_yes->next!=NULL)
				{
					if(temp_yes->patientId == discharge)
					{
						//newNode->next=temp->next;
		    			//temp->next=newNode;
		    			billCalculation(temp_yes);
						found=1;
		    			break;
					}
					else
						temp_yes=temp_yes->next;
				}
				if(temp_yes->patientId==discharge) 
				{
					billCalculation(temp_yes);
					found=1;
				}
				
				if(found==0) cout<<"NO SUCH PATIENT FOUND"<<endl;
				else if(found==1) 
				{
					del(discharge,1);
					COUNT_S--;
				}
			}
			else
				continue;
			}
			
		}
		else if(ch==2)
		{
			cout<<"**************************DOUBLE OCCUPANCY BED LIST******************************"<<endl;
			
			if(COUNT_D==0)
				cout<<"********CURRENTLY THERE ARE NO ENTRIES TO DISPLAY IN DOUBLE OCCUPANCY**********\n\n";
			else
			{
			//display_Double();
			sort(2);
			cout<<"AVAILABLE SEATS : "<<(10-COUNT_D)<<endl;
			char yn;
			cout<<"IS THERE A PATIENT TO BE DISCHARGED?\n\n ENTER Y FOR YES OR ANYTHING ELSE TO QUIT : "<<endl;
			cin>>yn;
			
			if(yn=='Y' || yn=='y')
			{
				string discharge;
				cout<<"ENTER PATIENT ID"<<endl;
				cin>>discharge;
				
				int found=0;
				struct Pat *temp_yes = head2; 
				while(temp_yes->next!=NULL)
				{
					if(temp_yes->patientId == discharge)
					{
						//newNode->next=temp->next;
		    			//temp->next=newNode;
		    			
						
						billCalculation(temp_yes);
		  			    found=1;
		    			break;
					}
					else
						temp_yes=temp_yes->next;
				}
				if(temp_yes->patientId==discharge && found==0) 
				{
					billCalculation(temp_yes);
					found=1;
				}
				if(found==0) cout<<"NO SUCH PATIENT FOUND"<<endl;
				else if(found==1)
				{
					del(discharge,2);
					COUNT_D--;
				}
			}
			else
				continue;
			}
		}
		else if(ch==3)
			break;
		else
			cout<<"CHOOSE AGAIN"<<endl;
		}while(ch!=3);
	}
	else if(choice==3)
	{
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~THANK YOU FOR USING OUR SERVICES~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		break;
	}
	else
	{
		cout<<"INVALID CHOICE"<<endl;
		continue;
	}
	}while(true);
	return 0;
}
























