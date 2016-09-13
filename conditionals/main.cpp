#include "condmatrix.h"

using namespace std;

int main()
{
        pair<int, int> index;
        double experiment_time = 0, total_time = 0;
	vector <int> b_param;
	int rem_ele;
        CondMatrix cond_matrix;
        cond_matrix.debugOff();

	// for (int fod = 5; fod <= 20; fod += 5)
	for (int fod = 5; fod <= 15; fod += 5)
	{       
		cout << "FOD size : " << fod << endl;
		for (int a = 1; a <= fod; a++)
		// for (int a = 1; a <= fod; a++)
		{
			cout << endl << "A size : " << a << endl;
			cond_matrix.clearMatrix();
			cond_matrix.newMatrix(fod - a, a);
			cond_matrix.genIncreasingMassValues();
			for (int arounds = 0; arounds < 1; arounds++)
			{       
				for (int b = 1; b < a; b++)
				{       
					cout << endl << "B size : " << b << endl;
					for (int brounds = 0; brounds < 3; brounds++)
					{       
						b_param.clear();
						for (int fill = 0; fill < a; fill++)
							b_param.push_back(fill);
						for (int rem = 1; rem <= a - b; rem++)
						{
							rem_ele = rand() % (a + 1 - rem);
							cout << "b_param_size : " << b_param.size() << "\t rem ele : " << rem_ele << endl;
							b_param.erase (b_param.begin() + rem_ele);
						}
						cout << "before filling" << endl;
						cond_matrix.fillingConditionedVecRandom(b_param);
						cout << "before belief" << endl;
						cout << "fod : " << fod <<  "\t a : " << a << "\t b : " << b << "\t" "Belief B :" << cond_matrix.calBeliefB() << endl;
						total_time += experiment_time;
					}
				}
			}
		}
		cout << "FoD size : " << fod << " Time spent : " << total_time << endl;
		total_time = 0;
	}

        return 0;
}
