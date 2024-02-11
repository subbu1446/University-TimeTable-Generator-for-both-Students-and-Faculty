#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
int rands (int i,int j)
{
   

    // Generate and print random numbers within the range
 
        int randomNum = rand() % (j - i + 1) + i;
        return randomNum;
}


class instructor {
  public:
    string name, id;
    vector<string> course_id;
    vector<string> course_name;
    vector<string> course_sec;
    vector<string> type;
    vector<int>credits;
    vector<vector<int> >i_day_slots;
    instructor (int n,int s)
    {
        i_day_slots.resize(n);
        for(int i=0;i<n;i++)
        {
            i_day_slots[i].resize(s);
        }
        for(int i=0;i<n;i++)
        {for(int j=0;j<s;j++)
            i_day_slots[i][j]=0;
        }
    }
    
};

int main() { srand(time(0));
    int  ns, nday, n_inst,s,n_electives;
    	vector<int> breaks;

    cout << "Enter total slots: ";
    cin >> s;
    string tim[s],lab_name;
    cout << "Enter timings slot wise:" << endl;
    for (int i = 0; i < s; i++) {
        cin >> tim[i];
    }
    cout << "Enter no.of working days: ";
    cin >> nday;
    string days[]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    cout << "Enter the no. of sections: ";
    cin >> ns;
    vector<string> sec_name(ns);
        	vector<vector<string> > labs(ns);
        
    cout<<"Enter section names\n";
    for (int i = 0; i < ns; i++) {
        cin >> sec_name[i];
    }
     cout << "Enter no. of instructors: ";
    cin >> n_inst;
    vector<instructor> inst(n_inst, instructor(nday,s));
    cout << "Enter the instructor details:" << endl;
    for (int i = 0; i < n_inst; i++) {
      cout<<"Enter instructor name:\n";
        cin >> inst[i].name;
        cout<<"Enter instructor ID:\n";
        cin >> inst[i].id;
        string courseid,type;
        char cont='y';
        while(cont=='y')
        { cout << "Enter course ID for instructor " << inst[i].name << ": ";
        cin >> courseid;
         inst[i].course_id.push_back(courseid);
         cout << "Enter course name for instructor " << inst[i].name<< ": ";
         string  course_name,course_sec;int course_credits;
         cin >> course_name;
         inst[i].course_name.push_back(course_name);
         cout << "Enter credits of the course " << inst[i].name << ": ";
         cin>>course_credits;
         inst[i].credits.push_back(course_credits);
         cout << "Enter section name for instructor " << inst[i].name << ": ";
         cin >> course_sec;
         inst[i].course_sec.push_back(course_sec);
        
         cout<<"do want to continue with same instructor, y/n \n ";
         cin>>cont;
        }
    }
   cout<<"Enter no.of electives in total\n";
    cin>>n_electives;
    cout<<"Enter elective names\n";
    vector<string> ele_names;
    for(int i=0;i<n_electives;i++)
    {  string name;
	   cin>>name;
    	ele_names.push_back(name);
    }
    cout<<"Enter no.of credits for each\n";
    int arre[n_electives];
    for(int i=0;i<n_electives;i++)
    {
    	cin>>arre[i];
    }
    cout<<"no.of sections taking each elective is \n";
    int n_sec;
     vector<int> n_e_sections;
    for(int i=0;i<n_electives;i++)
    {
         cin>>n_sec;
          n_e_sections.push_back(n_sec);
		 	
    }
    
    
    vector<vector<string> > e_section_name(n_electives);
    for(int i=0;i<n_electives;i++)
    {
    	cout<<"Enter the corresponding section that offering this elective in order of elective list for elective "<<i+1<<"\n";
    	string names;
    	for(int j=0;j<n_e_sections[i];j++)
    	{
	    	cin>>names;
	    	e_section_name[i].push_back(names);
	    }
    }
    
    string timetable1[ns][nday][s];
    string timetable2[inst.size()][nday][s];
    int slots_check[nday][s];
    for(int i=0;i<ns;i++)
    {
    	for(int j=0;j<nday;j++)
    	{
	    	for(int k=0;k<s;k++)
	    	{
	    		timetable1[i][j][k]="Lib";
	    		timetable2[i][j][k]="Ls";
	    	}
	    }
    }
    for(int i=0;i<nday;i++)
    {
    	for(int j=0;j<s;j++)
    	{
	    	slots_check[i][j]=0;
	    }
    }
    vector<vector<int> > slots_of_electives(n_electives);
    for(int i=0;i<n_electives;i++)
    {
    	slots_of_electives[i].resize(nday);
    }
    for(int i=0;i<n_electives;i++)
    {
    	
    	for(int j=0;j<nday;j++)
    	{
	    	slots_of_electives[i][j]=-1;
	    }
    }
    
    for(int i=0;i<n_electives;i++)
    {  
    	for(int j=0;j<nday;j++)
    	{if(arre[i]>0)
		 {int counts=0;
	    	for(int k=0;k<s;k++)
	    	{
	    		if(slots_check[j][k]==0)
	    		{
		    		counts++;
		    	}
	    	}
	    	if(counts==0)
	    	{	slots_of_electives[i][j]=-1;
	    		continue;
	    	}
	    	
	    	else 
	    	 {	int random;
		    	random = rands(0,s-1);
		    	cout<<random;
 	    	  while(slots_check[j][random]!=0)
	    		{
		    		random = (rands(0,s-1));
		    		cout<<random;
		    	}
		    	slots_of_electives[i][j]=random;
		    	slots_check[j][random]=1;
		    	arre[i]--;
	    	}
	    	
		 }
		 else{
 			break;
 		}
	    
    	
    }
}
cout<<"executed 1\n";
for(int i=0;i<slots_of_electives.size();i++)
    {
    	
    	for(int j=0;j<slots_of_electives[i].size();j++)
    	{
	    	cout<<slots_of_electives[i][j];
	    }
	    cout<<endl;
    }
    for(int i=0;i<ele_names.size();i++)
    {
    	for(int j=0;j<e_section_name[i].size();j++)
    	{ for(int k=0;k<sec_name.size();k++)
	    	{if(sec_name[k]==(e_section_name[i][j]))
	    	 {
	    		for(int l=0;l<slots_of_electives[i].size();l++)
	    		{
		    		if(slots_of_electives[i][l]!=-1)
		    		{
		    			timetable1[k][l][slots_of_electives[i][l]]=ele_names[i];
		    			
		    			 
		    		}
		    	}
	    	 }
	    	}
	    }
	   
    }
    
    for(int i=0;i<ele_names.size();i++)
    {
    	for(int j=0;j<inst.size();j++)
    	{
	    	for(int k=0;k<inst[j].course_name.size();k++)
	    	{
	    		if(ele_names[i]==inst[j].course_name[k])
	    		{
		    	for(int l=0;l<slots_of_electives[i].size();l++)
	    		{
		    		if(slots_of_electives[i][l]!=-1)
		    		{
		    			timetable2[j][l][slots_of_electives[i][l]]=ele_names[i];
		    			inst[j].credits[k]=0;
		    			inst[j].i_day_slots[l][slots_of_electives[i][l]] =1;
		    		}
		    	}
		    	}
	    	}
	    }
	   
    }
 
    for(int i=0; i<ns;i++)
   {
    for(int l=0;l<inst.size();l++)
    { 
        for(int a=0;a<inst[l].course_sec.size();a++)
        { 
             for(int j=0;j<nday;j++)
             { 
                      for(int k=0;k<s;k++)
                      {cout<<inst[l].course_sec[a];
                        if(sec_name[i]==(inst[l].course_sec[a]) && inst[l].credits[a]>0)
                        { if(timetable1[i][j][k]==("Lib"))
                           {if(inst[l].i_day_slots[j][k]==0)
                            { timetable1[i][j][k]=inst[l].course_name[a];
                              timetable2[l][j][k]=sec_name[i]+"("+inst[l].course_name[a]+")";
                            inst[l].credits[a]--;
                            inst[l].i_day_slots[j][k]=1;
                            }
                            else
                            {
                            for(int m=0;m<s;m++)
                             {
                                if(inst[l].i_day_slots[j][m]==0 && timetable1[i][j][m]=="Lib")
                                {
                                    timetable1[i][j][m]=inst[l].course_name[a];
                                    timetable2[l][j][m]=sec_name[i]+"("+inst[l].course_name[a]+")";
                                     inst[l].credits[a]--;
                                    inst[l].i_day_slots[j][m]=1;break;
                                }
                             }
                            }
                           }  
                        }
                      }
             }
          
        }
    }
      
   }
    
    
    string timetable3[ns][nday+1][s+1];
 string timetable4[inst.size()][nday+1][s+1];
    for(int i=0; i<ns;i++)
   {
    for(int j=0;j<nday+1;j++)
    { 
        for(int k=0;k<s+1;k++)
        { if(j==0 && k==0)
          timetable3[i][j][k]=sec_name[i];
         else if(k==0 && j>0)
          {
             timetable3[i][j][k]=days[j-1];
          }
         else if(j==0 && k>0)
          {
               timetable3[i][j][k]=tim[k-1];
          }
          else
          {
            timetable3[i][j][k]=timetable1[i][j-1][k-1];
          }
        }
    }
   }
     for(int i=0; i<inst.size();i++)
   {
    for(int j=0;j<nday+1;j++)
    { 
        for(int k=0;k<s+1;k++)
        { if(j==0 && k==0)
          timetable4[i][j][k]=inst[i].name;
         else if(k==0 && j>0)
          {
             timetable4[i][j][k]=days[j-1];
          }
         else if(j==0 && k>0)
          {
               timetable4[i][j][k]=tim[k-1];
          }
          else
          {
            timetable4[i][j][k]=timetable2[i][j-1][k-1];
          }
        }
    }
   }
    
   ofstream timetable_sec("D:/AMRITA/Semesters/semester-6/open lab/timetable/timetable_sec.docx");
   ofstream timetable_inst("D:/AMRITA/Semesters/semester-6/open lab/timetable/timetable_inst.docx");
   for(int i=0; i<ns;i++)
   {
    for(int j=0;j<nday+1;j++)
    { 
        for(int k=0;k<s+1;k++)
        { 
          timetable_sec<< timetable3[i][j][k]<<"\t\t";
        }
         timetable_sec<<"\n";
    }
     timetable_sec<<"\n";
   }
   for(int i=0; i<ns;i++)
   {
    for(int j=0;j<nday+1;j++)
    { 
        for(int k=0;k<s+1;k++)
        { 
          timetable_inst<< timetable4[i][j][k]<<"\t";
        }
        timetable_inst<< "\n";
    }
    timetable_inst<< "\n";
   }
   timetable_sec.close();
   timetable_inst.close();
    
    return 0;
}
