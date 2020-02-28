#include <iostream>
#include <vector>
#include <sstream>
#include "VolImage.h"
#include <fstream>
#include <math.h>
#include <string> 

using namespace std;


	VolImage::VolImage(){
		width = 0;
		height = 0;
		num_images=0;
		vector<u_char**> slices;
		
		}
		
	VolImage::~VolImage(){
		for(unsigned int i = 0; i < slices.size(); i++){
			
			for(int x =0; x < height; x++){
				
				delete [] slices[i][x];
				}
			delete [] slices[i];
			}
		
		
		}
		
	 bool VolImage::readImages(string baseName){
		 string line;
		 vector <string> vecWords;
		 ifstream myfile ("brain_mri_raws/"+ baseName+".data");
		 if(myfile.is_open()){
			
			string oneword;
			 while(getline(myfile, line)){
				 stringstream ss(line);
				 while(getline(ss,oneword,' ')){
					 vecWords.push_back(oneword);
					 }
				width=stoi(vecWords[0]);
				height=stoi(vecWords[1]);
				num_images=stoi(vecWords[2]);
				
				 }
				myfile.close();
			 }
		 else{  cout<< "file not found"<<endl;}
		 
		 for(int i = 0; i< num_images; i++){
			 int counter __attribute__((unused)) =0;
			 streampos size;
			 char* memblock __attribute__((unused));
		     u_char** rawarray = new u_char* [height];
		     for(int i = 0; i< height ;i++){
				 rawarray [i] =new u_char [width];
				 }
			 ifstream file("brain_mri_raws/"+ baseName+to_string(i)+".raw", ios::in| ios::binary|ios::ate);
			 if(file.is_open()){
				 size = file.tellg();
		         memblock = new char [size];
                 file.seekg (0, ios::beg);
                 file.read(memblock, size);
                 file.close();
			 }
					for(int x =0; x<height ; x++){
						for(int j = 0; j < width ; j++){
						 rawarray[x][j]= memblock[counter];
						 counter++;
						 }
					 
						
						}
					
					 
				  slices.push_back(rawarray);
				  
				  
				 
			 }
		 
		
		 return 0;
		 }
		 
	void VolImage::diffmap(int sliceI, int sliceJ, string output_prefix){
		int size = height*width;
		char* output __attribute__((unused)) = new char[size];
		ofstream fs;
		fs.open(output_prefix+".raw",ios::out| ios::binary| ios::app);
		if(!fs.is_open()){
			cout<< "Cannot Open File "<< output_prefix << endl; 
			}
		else{
			
			
			int count __attribute__((unused)) =0;
			for(int r = 0; r < height; r++){
				for(int c = 0; c < width; c++){
					output[count]= (unsigned char)(abs((float)slices[sliceI][r][c] - (float)slices[sliceJ][r][c])/2);
					count++;
					}
				}
			fs.write(output,size);
			fs.close();
			}
		
		}
		
		
	void VolImage::extract(int sliceId, string output_prefix){
			int size = height*width;
			char* output __attribute__((unused)) = new char[size];
			int count __attribute__((unused)) =0;
			ofstream fs;
			fs.open(output_prefix+".raw",ios::out| ios::binary);
		if(!fs.is_open()){
			cout<< "Cannot Open File "<< output_prefix << endl; 
			}
		else{
			
			for(int r = 0; r < height; r++){
				for(int c = 0; c < width; c++){
					output[count]= slices[sliceId][r][c];
					count++;
					}
				}
			fs.write(output,size);
			fs.close();
			}
		ofstream myfile("Extraction.data");
		if(myfile.is_open()){
			myfile<< to_string(height)+" "+to_string(width)+" 1";
			myfile.close();
			}
		else{
			cout<< "Unable to open file"<<endl;
			}
		
		}
		
	int VolImage::volImageSize(void){
		int size = height*width*num_images + sizeof(u_char)*height*width;
		return size;
		
		}
		
	int VolImage::volNumImage(void){
		return num_images;
		
		}
		
		
	
