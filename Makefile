CXX=g++

volimg:	VolImage.o Drivervol.o
	$(CXX) VolImage.o Drivervol.o -o VolImage

volimage.o:	VolImage.cpp VolImage.h
	$(CXX) VolImage.cpp -c

Drivervol.o: Drivervol.cpp VolImage.h
	$(CXX) Drivervol.cpp -c
run:
	./VolImage MRI
extract:
	./VolImage MRI -x 55 output
diff:
	./VolImage MRI -d 1 2 different

clean:
	@rm -f *.o VolImage
