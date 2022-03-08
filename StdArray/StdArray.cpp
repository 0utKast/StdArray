#if 0
#include <array>

std::array<int, 3> miArray; // declara un integer array de tamaño 3



std::array<int, 6> miArray = { 3, 5, 2, 9, 7, 2 }; // inicializador de lista
std::array<int, 7> miArray2 { 3, 5, 2, 9, 7, 2, 8 }; // lista de initialización


//Hasta C++ 17
std::array<int, > miArray = { 3, 5, 2, 9, 7, 2 }; //ilegal, tamaño array obligatorio
std::array<int> miArray2{ 3, 5, 2, 9, 7, 2, 8 }; // ilegal, tamaño array obligatorio


//Desde C++ 17
std::array miArray{ 3, 5, 2, 9, 7, 2 }; // El tipo es deducido a std::array<int, 5>
std::array miArray{ 4.7, 6.31 }; // El tipo es deducido a std::array<double, 2>

//Desde C++ 20
auto miArray1{ std::to_array<int, 6>({ 9, 7, 5, 3, 1,6 }) }; // Especifica tipo y tamaño
auto miArray2{ std::to_array<int>({ 9, 7, 5, 3, 1 }) }; // Especifica sólo tipo, deduce tamaño
auto miArray3{ std::to_array({ 9, 7, 5, 3, 1 }) }; // Deduce tipo y tamaño


#include <array>
#include <iostream>
int main()
{
	std::array<int, 6> miArray;
	miArray = { 0, 1, 2, 3, 4, 3 }; // okay
	miArray = { 9, 8, 7 }; // okay, elementos 3, 4 y 5 configurados a 0
	//miArray = { 0, 1, 2, 3, 4, 5, 6 }; // ilegal, demasiados elementos 
									   //en la lista de inicializadores

	std::cout << miArray[1] << '\n';
	miArray[2] = 6;
	std::cout << miArray[2] << '\n';
	std::cout << miArray[3] << '\n';
}



#include <array>
#include <iostream>
int main()
{
	std::array miArray{ 3, 6, 5, 2, 1 };
	std::cout << miArray[1] << '\n';
	miArray.at(1) = 7; // elemento 1 array es válido, le asigna valor de 7
	std::cout << miArray[1] << '\n';
	miArray.at(9) = 2; // element 9 array es inválido, error en ejecuión
}



#include <array>
#include <iostream>
int main()
{
	setlocale(LC_ALL, "es_ES.UTF-8");
	std::array miArray{ 6.2, 7.4, 7.3, 6.6, 2.8 };
	std::cout << "tamaño: " << miArray.size() << '\n';
}



#include <array>
#include <iostream>

void imprimirTam(const std::array <double,5> &miArray)
{
	std::cout << "tamaño: " << miArray.size() << '\n';
}

int main()
{
	setlocale(LC_ALL, "es_ES.UTF-8");
	std::array miArray{ 6.2, 7.4, 7.3, 6.6, 2.8 };

	imprimirTam(miArray);

	return 0;
}



#include <array>
#include <iostream>
int main()
{
	std::array myArray{ 10, 8, 6, 4, 2 };

	for (int elemento : myArray)
		std::cout << elemento << ' ';
}



#include <algorithm> // para std::sort
#include <array>
#include <iostream>

int main()
{
	std::array miArray{ 4, 6, 2, 10, 8 };
	//std::sort(miArray.begin(), miArray.end()); // ordena el array ascendente
    std::sort(miArray.rbegin(), miArray.rend()); // ordena el array descendente

	for (int elemento : miArray)
		std::cout << elemento << ' ';

	std::cout << '\n';

	return 0;
}





#include <array>
#include <iostream>

void imprimirArray(const std::array<double,5> &miArray)
{
	for (auto elemento : miArray)
		std::cout << elemento << ' ';
	std::cout << '\n';
}

int main()
{
	std::array miArray5{ 9.0, 7.2, 5.4, 3.6, 1.8 }; // tipo deducido como std::array<double, 5>
	imprimirArray(miArray5); // su tipo y tamaño coincide con los que espera la función
	std::array miArray2{ 9, 7, 5, 3, 1 }; // tipo deducido como std::array<int, 5>
	imprimirArray(miArray2);
	

	return 0;
}






#include <array>
#include <cstddef>
#include <iostream>

// imprimirArray es una plantilla de función
template <typename T, std::size_t tamanho> // parametriza el tipo y el tamaño
void imprimirArray(const std::array<T, tamanho> &miArray)
{
	for (auto elemento : miArray)
		std::cout << elemento << ' ';
	std::cout << '\n';
}

int main()
{
	std::array <double, 5> miArray5{ 7.0, 3.2, 6.4, 2.6, 1.8 };
	imprimirArray(miArray5);

	std::array <double, 7> miArray7{ 8.0, 5.2, 2.4, 7.6, 2.8, 1.2, 0.7 };
	imprimirArray(miArray7);

	std::array <int, 4> miArray4{ 3, 5, 7, 4 };
	imprimirArray(miArray4);

	return 0;
}



#include <iostream>

int main()
{
	std::cout << sizeof(int) << '\n';

	return 0;
}





#include <cstddef> // std::size_t
#include <iostream>

int main()
{
	std::cout << sizeof(std::size_t) << '\n';

	return 0;
}
#endif


#include <array>
#include <iostream>

struct Casa
{
	int numero{};
	int pisos{};
	int vivPorPiso{};
};

int main()
{
	std::array<Casa, 4> casas{};

	casas[0] = { 13, 4, 30 };
	casas[1] = { 14, 3, 10 };
	casas[2] = { 15, 3, 40 };
	casas[3] = { 16, 2, 12 };

	for (const auto &viviendas : casas)
	{
		std::cout << "Casa Num. " << viviendas.numero
			<< " tiene " << (viviendas.pisos * viviendas.vivPorPiso)
			<< " viviendas\n";
	}

	return 0;
}

#if 0
#endif