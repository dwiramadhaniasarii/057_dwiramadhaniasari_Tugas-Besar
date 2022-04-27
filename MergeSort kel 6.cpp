// Merge sort in C++
#include <iostream>
using namespace std;

// Deklarasi void merge integer array, integer l, integer m, integer r
// Menggabungkan dua subarray L dan M menjadi arr
	void merge(int arr[], int l, int m, int r)
	{
	    // Membuat salinan dari subarray
	    int i, j, k;
	    int n1 = m - l + 1;	
	    int n2 = r - m;
	
	    int L[n1], R[n2];
	
	    for (i = 0; i < n1; i++)
	        L[i] = arr[l + i];
	    for (j = 0; j < n2; j++)
	        R[j] = arr[m + 1 + j];
	        
	    i = 0;
	    j = 0;
	    k = l;
	// membuat temp array 
	// Menggabungkan kedua bagian
	    while (i < n1 && j < n2)
	    {
	        if (L[i] <= R[j]){
	            arr[k] = L[i];
	            i++;
	        }
	        else{
	            arr[k] = R[j];
	            j++;
	        }
	        k++;
	    }
	// Menyalin elemen yang tersisa dari i ke mid ke temp
	    while (i < n1){
	        arr[k] = L[i];
	        i++;
	        k++;
	    }
	// Menyalin elemen yang tersisa dari j ke tinggi ke temp
	    while (j < n2)
	    {
	        arr[k] = R[j];
	        j++;
	        k++;
	    }
	}
	// Fungsi untuk membagi array menjadi dua bagian
	void mergeSort(int arr[], int l, int r)
	{
	    if (l < r){
			// m adalah titik di mana array dibagi menjadi dua subarray
	        int m = l + (r - l) / 2;
	
	        mergeSort(arr, l, m);
	        mergeSort(arr, m + 1, r);
	        
			// Gabungkan subarray yang diurutkan
	        merge(arr, l, m, r);
	    }
	}
	// Cetak array
	void show(int Arr[], int size)
	{
	    int i;
	    for (i = 1; i <= size; i++)
	        cout <<"[" << Arr[i] << "]";
	}
	
// Driver program
// memasukkan banyak data dan banyak array
	int main()
	{
	    int size;
	    cout << "\nMasukan Banyak Data : ";
	    cin >> size;
	
	    int arr[size];
	
	    for (int i = 0; i < size; ++i)
	    {
	        cout << "\nMasukan Data array ke "<<i<<" :";
	        cin >> arr[i];
	    }
		// memanggil mergesort
	    mergeSort(arr, 0, size);
// Menampilkan hasil sorting 
	    cout << "Hasil data terurut : ";
	    show(arr, size);
	    
	    cout<<" "<<endl;
  		cout<<"\ndevelop @kelompok_6";

	    
	    return 0;
	}
