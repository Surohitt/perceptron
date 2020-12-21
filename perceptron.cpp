#include <vector> 
#include <iostream>
#include <stdlib.h>

double fRand(double fMin, double fMax){
	double f = (double)rand()/RAND_MAX;
	return fMin + f * (fMax - fMin);
}


class perceptron{
	private:
		// Bias included in weights
		std::vector<double> weights;
		int epochs = 100;	
		double learningRate = 0.1;	
		void randomizeWeights(){
			for (int i=0; i<weights.size(); i++){
				weights[i]= fRand(1.0, 5.0);
			}
		}
	
	public:
		void setLR(double lr){
			learningRate = lr;
		}
		void setEpochs(int numberEpochs){
			epochs = numberEpochs;
		}
		void setWeightSize(int size){
			weights.resize(size+1);	
			randomizeWeights();	
		}
		int getWeightSize(){
			return weights.size();		
		}
		std::vector<double> getWeights(){
			return weights;
		}
		
		double calculateOutput(std::vector<double> inputData){
			double output=0;
			for (int i=0; i<inputData.size(); i++){
				output += (inputData[i]*weights[i]);
			}
			return output;
		}
};


int main(){
	std::cout<<"How many weights?:\n";
	int numWeights;
	std::cin>>numWeights;

	perceptron percep;
	percep.setWeightSize(numWeights);

	int weightSize=percep.getWeightSize();

	std::cout<<"Number of Weights is:\n" << weightSize << "\n";
	
	// Data has to be the same size as weights
	std::vector<double>data(weightSize);

	for (int i=0; i<weightSize; i++){
		data[i] = fRand(1.0, 5.0);
	}

	for (int i=0; i<weightSize; i++){
		std::cout<<data[i] << "\n";
	}
	
	std::vector<double>weights = percep.getWeights();

	for (int i=0; i<weightSize; i++){
		std::cout<<weights[i] << "\n";
	}

	std::cout<<"Output:\n"<< percep.calculateOutput(data) <<"\n";
	
}

