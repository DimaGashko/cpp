#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	FILE *fileInput, *fileOutput;

	const int periods = 10;
	const float k = 0.09, inflation = 0.045;

	fileInput = fopen("input.txt", "r");
	fileOutput = fopen("output.txt", "w");

	if (!fileInput || !fileOutput) {
		printf("Cannot open files");
		system("pause");
		return 0;
	}

	float n;
	fscanf(fileInput, "%f", &n);

	fprintf(fileOutput, "Начальная сумма: %.2f\n\n", n);
	fprintf(fileOutput,
		"+------+------------+------------+\n"
		"| Год  | Сумма      | Реально    |\n"
		"+------+------------+------------+\n"
	);

	float curN = n, real = n;

	for (int i = 1; i <= periods; i++) {
		curN *= (1 + k);
		real = curN * (1 - inflation);

		fprintf(fileOutput,
			"|  %-2d  | %-10.2f | %-10.2f |\n"
			"+------+------------+------------+\n",
			i, curN, real
		);
	}

	fclose(fileInput);
	fclose(fileOutput);

	return 0;
}