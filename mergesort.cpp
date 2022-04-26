// Merge sort in C++

#include <iostream>
using namespace std;

// Menggabungkan dua subarray L dan M menjadi arr
void merge(int arr[], int p, int q, int r) {
  
  // Membuat salinan dari subarray L A[p..q] dan M A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Pertahankan indeks sub-array dan larik utama saat ini
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

   // Sampai kita mencapai salah satu ujung L atau M, pilih yang lebih besar di antara
   // elemen L dan M dan letakkan di posisi yang benar di A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

 // Saat kita kehabisan elemen di L atau M,
 // ambil elemen yang tersisa dan masukkan ke A[p..r]
  while (i < n1) {   // Kita keluar dari loop sebelumnya karena j < n2 tidak berlaku
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {  // Kita keluar dari loop sebelumnya karena i < n1 tidak berlaku
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Bagilah array menjadi dua subarray, urutkan dan gabungkan
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m adalah titik di mana array dibagi menjadi dua subarray
    int q = l + (r - l) / 2;

    mergeSort(arr, l, q);
    mergeSort(arr, q + 1, r);

    // Gabungkan subarray yang diurutkan
    merge(arr, l, q, r);
  }
}

// Cetak array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Driver program
int main() {
  int myarray[10];
  //int arr_size = sizeof(myarray)/sizeof(myarray[0]);
  int arr_size = 5;

  cout << "Masukan 5 elemen data yang akan diurutkan : " << endl;
  for (int i = 0; i < 5; i++) {
    cin >> myarray[i];
  }
  cout << "Data sebelum diurutkan :" << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarray[i] << " ";
  }
  cout << endl;
  
  // memanggil mergesort(array,kanan,kiri) 
  mergeSort(myarray, 0, (arr_size - 1)); 
  
  // menampilkan hasil sorting melalui looping input
  cout << "Hasil data terurut :" << endl;
  for (int i = 0; i < 5; i++) {
    cout << myarray[i] << " ";
  }
  
  cout<<" "<<endl;
  cout<<"\ndevelop @kelompok_6";

  return 0;
}
