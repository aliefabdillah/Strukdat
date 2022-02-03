/* 
    - di pemrogaman root ada di paling atas dan leaf ada di palign bawah
    dan tidak ada anak

    - pada tree ada juga level, atau tingkatan berdasarkan tingkat pada tree
    - ada beberapa cara menggambarkan pohom:
    1. grafik
    2. diagram venn
    3. notasi kurung
    4. indentasi (seperti progam if dll)
    
    - ada jenis-jenis pohon biner
    1. pohon biner lengkap
    pohon biner adalah pohon yang masing masing simpulnya max memiliki 2 anak saja
    dalam biner anaknya bisa di bagi 2 menjadi pohon kiri dan pohon kanan
    
        - pohon biner condong kiri (left skewed)
         dimana simpul yang dimiliki hanya anak sebelah kiri dari simpul
        - pohon biner condong kanan (right skewed)
         dimana simpul yang dimiliki hanya anak sebelah kanan dari simpul
    
    2. pohon biner sembarang
        pohon yang bebas memiliki anak atau tidak

    
    operasi penulurusan pada pohon biner
    1. pre order = kunjungan dari akar kemudian pohon kiri sampai habis lalu ke pohon kanan mirip DFS
    2. in order = dimulai dari anak kiri ke akar lalu ke anak kanan
    3. post order = dimulai dari anak paling kiri sampai child sebelun root lalu ke anak paling kanan lalu ujungnya ke akar di orint berdasar layer dari bawah
    4. level order = berdasar level dari atas ke bawah

    implementasi pada strukdat:
    di representasikan secara dinamis
    - ada pointer ke poho kiri dan pointer ke pohon kanan
 */

//kode progam

#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamat_simpul;
typedef struct smp
{
    char kontainer;
    alamat_simpul right;
    alamat_simpul left;
}simpul;

typedef struct 
{
    simpul* root;
}tree;

//prosedur
void make_tree(char c, tree *T)
{
    simpul *baru;
    baru = (simpul *) malloc (sizeof (simpul));

    //memasukan data elemen baru ke tree
    baru->kontainer = c;
    baru->right = NULL;
    baru->left = NULL;
    (*T).root = baru;           //root mengarah ke elemen baru
    baru = NULL;
}

// menambahkan anak kiri dan kanan di root
void add_right(char c, simpul *root)
{
    if (root->right == NULL)
    {
        // jika simpul root sebelah kanan kosong
        simpul *baru;
        baru = (simpul *) malloc (sizeof (simpul));

        baru->kontainer = c;        //memasukan elemen baru ke kontainer c
        baru->right = NULL;         //simpul kanan pada baru masih null
        baru->left = NULL;          //simpul kiri pada baru null
        root->right = baru;         //simpul kanan pada root menunjuk ke baru
    }
    else
    {
        printf("sub pohon kanan telah terisi");
    }
}


void add_left(char c, simpul *root)
{
    if (root->left == NULL)
    {
        // jika simpul root sebelah kiri kosong
        simpul *baru;
        baru = (simpul *) malloc (sizeof (simpul));

        baru->kontainer = c;        //memasukan elemen baru ke kontainer c sebelah kiri
        baru->right = NULL;         //simpul kanan pada baru masih null
        baru->left = NULL;          //simpul kiri pada baru null
        root->left = baru;         //simpul kiri pada root menunjuk ke baru
    }
    else
    {
        printf("sub pohon kiri telah terisi");
    }
}


//menghapus semua simpul pada pohon
void del_all(simpul *root)
{
    if (root != NULL)
    {
        del_all(root->left);            //menghapus anak kiri    
        del_all(root->right);           //menghapus anak kanan
        free(root);     
    }
}

//mengahpus anak sebelah kanan
void del_right(simpul *root)
{
    //jika root tidak kosong
    if (root != NULL)
    {
        //jika simpul kanan dari root tidak null
        if (root->right != NULL)
        {
            //rekursif sampai ketemu null
            del_all(root->right);
            //  setelah itu baru di hapus semua anak di sebelah kanan
            root->right = NULL;

        }
        
    }
    
}

//mengahpus anak sebelah kiri
void del_left(simpul *root)
{
    //jika root tidak kosong
    if (root != NULL)
    {
        //jika anak kiri dari root tidak null
        if (root->left != NULL)
        {
            //rekursif sampai ketemu null
            del_all(root->left);
            //  setelah itu baru di hapus baru hapus semua anak sebelh kiri
            root->left = NULL;

        }   
    }
}

//prosedur penlusuran in order, pre order, post order
void print_pre_order(simpul *root)
{
    if (root != NULL)
    {
        printf(" %c ", root->kontainer);
        print_pre_order(root->left);
        print_pre_order(root->right);
    }   
}


void print_in_order(simpul *root)
{
    if (root != NULL)
    {
        print_in_order(root->left);
        printf(" %c ", root->kontainer);
        print_in_order(root->right);
    }   
}

void print_post_order(simpul *root)
{
    if (root != NULL)
    {
        print_post_order(root->left);
        print_post_order(root->right);
        printf(" %c ", root->kontainer);
    }
}


//copy tree adalah mengcopy sebuah pohon menjadi pohon baru
//berjalan menyusuri setiap simpul pada pohon 1 jika simpul nya tidak null disalin ke pohon 2
// **root2 memiliki 2bintang karena bintang 1 adalah simpul dan yang kedua adalah pass by reference
void copy_tree(simpul *root1, simpul **root2)
{

    //jika simpul di root 1 tidak null
    if (root1 != NULL)
    {
        (*root2) = (simpul *) malloc (sizeof (simpul));

        //isi simpul root pohon kedua sama dengan root 1
        (*root2)->kontainer = root1->kontainer;
        (*root2)->left = NULL;
        (*root2)->right = NULL;

        //jika simpul kiri dari root tidak null
        if (root1->left != NULL)
        {
            //rekursif anak kiri ke pohon kedua
            copy_tree(root1->left, &(*root2)->left);
        }
        
        //jika simpul kanan dari root tidak null
        if (root1->right != NULL)
        {
            //rekursif anak kanan ke pohon kedua
            copy_tree(root1->right, &(*root2)->right);
        }
    }
}

//pengecekan apakah 2 pohon memiliki yang sama
int is_equal(simpul *root1, simpul *root2)
{
    int hasil = 1;   
    //jika sama akan bernilai 1
    //jika beda akan bernilai 0

    //jika sama sama tidak null pada kedua pohon
    if ((root1 != NULL) && (root2 != NULL))
    {
       
        //jika isi kedua simpul dari pohon berbeda
        if (root1->kontainer != root2->kontainer)
        {
            hasil = 0;
        }
        else
        {
            // jika masih sama lakukan rekursif sampai ketemu NULL pada simpul
            //rekursif ke kiri
            hasil = is_equal(root1->left, root2->left);

            //rekursif ke kanan
            if (hasil != 0)
            {
                hasil = is_equal(root1->right, root2->right);
            }
        }
    }
    else
    {
        if ((root1 != NULL) || (root2 != NULL))
        {
            // jika salah satu simpul ada yang null
            hasil = 0;
        }
    }
    
    return hasil;  
    
}

int main(){
    tree T;
    make_tree('A', &T);
    add_left('B', T.root);
    add_right('C', T.root);
    add_left('D', T.root->left);
    add_right('E', T.root->left);
    add_right('F', T.root->right);

    // printf("==================\n");
    // printf("pre order\n");
    // print_pre_order(T.root);

    // printf("\n==================\n");
    // printf("in order\n");
    // print_in_order(T.root);

    // printf("\n==================\n");
    // printf("post order\n");
    // print_post_order(T.root);
    // printf("\n==================\n");

    //membuat dua buah pohon
    tree T2;
    make_tree('A', &T2);
    add_left('B', T2.root);
    add_right('C', T2.root);
    add_left('D', T2.root->left);
    add_right('E', T2.root->left);
    add_right('F', T2.root->right);

    //copy_tree(T.root, &T2.root);
    print_pre_order(T.root);
    // printf("\n");
    // print_pre_order(T2.root);

    //cek sama
    if (is_equal(T.root, T2.root) == 1)
    {
        printf("\npohon sama\n");
    }
    else
    {
        printf("\npohon tidak sama\n");
    }

    //menghapus anak dari simpul kiri setelah root
    // del_right(T.root->left);
    // del_left(T.root->left);

    // printf("\n==================\n");
    // printf("pre order\n");
    // print_pre_order(T.root);
    // printf("\n==================\n");

    return 0;
}