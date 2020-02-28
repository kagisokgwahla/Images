#include "VolImage.h"

using namespace std;

int main(int argc, char* argv[]){
	
	VolImage vol;
	vol.readImages(string(argv[1]));
	
	
	if(argc == 2){
		cout<<"Number of images:";
		cout<<vol.volNumImage()<<endl;
		cout<<"Number of bytes:"; 
		cout<< vol.volImageSize()<<endl;
		}
	else if(argc == 5){
		string prefix = string(argv[4]);
		string sliceId = string(argv[3]);
		int id = stoi(sliceId);
		
		
		vol.extract(id, prefix);
		
		}
		
	else if(argc == 6){
		string prefix = string(argv[5]);
		string slicei = string(argv[3]);
		string slicej = string(argv[4]);
		int i = stoi(slicei);
		int j = stoi(slicej);
		vol.diffmap(i,j,prefix);
		}
		
	else if(argc <2){
		cout<<"Incorrect input"<<endl;
		
		}
	
	
	}
