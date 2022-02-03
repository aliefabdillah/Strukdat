#include <stdio.h>
#include <malloc.h>

typedef struct smp *alamatsimpul;
typedef struct smp
{
    char kontainer;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct
{
    simpul *root;
} tree;

void makeTree(char c, tree *T)
{
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));
    node->kontainer = c;
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addChild(char c, simpul *root)
{
    if (root != NULL)
    {
        /* jika simpul root tidak kosong,
        berarti dapat ditambahkan simpul anak
        */
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        baru->kontainer = c;
        baru->child = NULL;

        if (root->child == NULL)
        {
            /* jika simpul root belum
            memiliki simpul anak maka simpul baru
            menjadi anak pertama */

            baru->sibling = NULL;
            root->child = baru;
        }
        else
        {
            if (root->child->sibling == NULL)
            {
                /* jika simpul root memiliki
                anak yang belum memiliki saudara, maka
                simpul baru menjadi anak kedua */
                baru->sibling = root->child;
                root->child->sibling = baru;
            }
            else
            {
                simpul *last = root->child;
                /* mencari simpul anak terakhir
                karena akan dikaitkan dengan simpul
                baru sebagai simpul anak terakhir yang
                baru, simpul anak terakhir adalah yang
                memiliki sibling simpul anak pertama,
                maka selama belum sampai pada simpul
                anak terakhir, penunjuk last akan
                berjalan ke simpul anak berikutnya */
                while (last->sibling !=
                       root->child)
                {
                    last = last->sibling;
                }
                baru->sibling =
                    root->child;
                last->sibling = baru;
            }
        }
    }
}

void delAll(simpul *root)
{
    if (root != NULL)
    {
        /* jika simpul root tidak kosong */
        if (root->child != NULL)
        {
            if (root->child->sibling == NULL)
            {
                /* jika hanya memiliki satu simpul anak */
                delAll(root->child);
                free(root);
            }

            else
            {
                simpul *bantu;
                simpul *proses;
                bantu = root->child;
                while (bantu->sibling != root->child)
                {
                    proses = bantu;
                    bantu = bantu->sibling;
                    delAll(proses);
                }
            }
            free(root);
        }
        else
        {
            free(root);
        }
    }
}
void delChild(char c, simpul *root)
{
    if (root != NULL)
    {
        simpul *hapus = root->child;
        if (hapus != NULL)
        {
            if (hapus->sibling == NULL)
            {
                /*jika hanya mempunyai satu anak*/
                if (root->child->kontainer == c)
                {
                    delAll(root->child);
                    root->child = NULL;
                }
                else
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
            else
            {
                /*jika memiliki lebih dari satu simpul
                anak*/
                simpul *prev = NULL;
                /*mencari simpul yang akan dihapus*/
                int ketemu = 0;
                while ((hapus->sibling != root->child) && (ketemu == 0))
                {
                    if (hapus->kontainer == c)
                    {
                        ketemu = 1;
                    }
                    else
                    {
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }

                /*memproses simpul anak terakhir karena
                belum terproses dalam pengulangan*/
                if ((ketemu == 0) && (hapus->kontainer == c))
                {
                    ketemu = 1;
                }
                if (ketemu == 1)
                {
                    simpul *last = root->child;
                    /* mencari simpul anak terakhir untuk
                    membantu proses atau pemeriksaan jika yang
                    dihapus nantinya anak terakhir */
                    while (last->sibling !=
                           root->child)
                    {
                        last = last->sibling;
                    }
                    if (prev == NULL)
                    {
                        /*jika simpul yang dihapus
                        anak pertama*/
                        if ((hapus->sibling ==
                             last) &&
                            (last->sibling == root->child))
                        {
                            /*jika hanya ada dua anak*/
                            root->child = last;
                            last->sibling = NULL;
                        }
                        else
                        {
                            /* jika memiliki simpul anak
                            lebih dari dua simpul */
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    }
                    else
                    {
                        if ((prev == root->child) && (last->sibling == root->child))
                        {
                            /* jika hanya ada dua simpul
                            anak dan yang dihapus adalah simpul
                            anak kedua */

                            root->child->sibling = NULL;
                        }
                        else
                        {
                            /* jika yang dihapus bukan
                            simpul anak pertama dan simpul root
                            memiliki simpul anak lebih dari dua
                            simpul */
                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    delAll(hapus);
                }
                else
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
        }
    }
}

simpul *findSimpul(char c, simpul *root)
{
    simpul *hasil = NULL;
    if (root != NULL)
    {
        if (root->kontainer == c)
        {
            hasil = root;
        }
        else
        {
            simpul *bantu = root->child;
            if (bantu != NULL)
            {
                if (bantu->sibling == NULL)
                {
                    /*jika memiliki satu simpul anak*/
                    if (bantu->kontainer == c)
                    {

                        hasil = bantu;
                    }

                    else
                    {

                        hasil = findSimpul(c, bantu);
                    }
                }
                else
                {
                    /*jika memiliki banyak simpul anak*/
                    int ketemu = 0;
                    while ((bantu->sibling != root->child) && (ketemu == 0))
                    {
                        if (bantu->kontainer == c)
                        {
                            hasil = bantu;
                            ketemu = 1;
                        }
                        else
                        {
                            hasil =
                                findSimpul(c, bantu);
                            bantu = bantu->sibling;
                        }
                    } /*memproses simpul anak terakhir karena belum terproses dalam
 pengulangan*/
                    if (ketemu == 0)
                    {
                        if (bantu->kontainer == c)
                        {
                            hasil = bantu;
                        }
                        else
                        {
                            hasil =
                                findSimpul(c, bantu);
                        }
                    }
                }
            }
        }
    }
    return hasil;
}
void printTreePreOrder(simpul *root)
{
    if (root != NULL)
    {
        printf(" %c ", root->kontainer);
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                /*jika memiliki satu simpul anak*/
                printTreePreOrder(bantu);
            }
            else
            {
                /*jika memiliki banyak simpul anak*/

                /*mencetak simpul anak*/
                while (bantu->sibling !=
                       root->child)
                {
                    printTreePreOrder(bantu);
                    bantu = bantu->sibling;
                }

                /*memproses simpul anak
                terakhir karena belum terproses
                dalam pengulangan*/
                printTreePreOrder(bantu);
            }
        }
    }
}
void printTreePostOrder(simpul *root)
{

    if (root != NULL)
    {
        simpul *bantu = root->child;

        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                /*jika memiliki satu simpul anak*/
                printTreePostOrder(bantu);
            }
            else
            {
                /*jika memiliki banyak simpul
                anak*/
                /*mencetak simpul anak*/
                while (bantu->sibling !=
                       root->child)
                {
                    printTreePostOrder(bantu);
                    bantu = bantu->sibling;
                }

                /*memproses simpul anak
                terakhir karena belum terproses
                dalam pengulangan*/

                printTreePostOrder(bantu);
            }
        }
        printf(" %c ", root->kontainer);
    }
}
void copyTree(simpul *root1, simpul **root2)
{
    if (root1 != NULL)
    {
        (*root2) = (simpul *)malloc(sizeof(simpul));
        (*root2)->kontainer = root1->kontainer;
        (*root2)->sibling = NULL;
        (*root2)->child = NULL;
        if (root1->child != NULL)
        {
            if (root1->child->sibling == NULL)
            {
                /*jika memiliki satu simpul anak*/
                copyTree(root1->child, &(*root2)->child);
            }

            else
            {
                /*jika memiliki banyak simpul anak*/
                simpul *bantu1 = root1->child;
                simpul *bantu2 =
                    (*root2)->child;

                while (bantu1->sibling !=
                       root1->child)
                {
                    copyTree(bantu1, &bantu2);
                    bantu1 = bantu1->sibling;
                    bantu2 = bantu2->sibling;
                }
                /*memproses simpul anak terakhir karena
                belum terproses dalam pengulangan*/
                copyTree(bantu1, &bantu2);
            }
        }
    }
}
int isEqual(simpul *root1, simpul *root2)
{
    int hasil = 1;
    if ((root1 != NULL) && (root2 != NULL))
    {
        if (root1->kontainer != root2->kontainer)
        {
            hasil = 0;
        }
        else
        {
            if ((root1->child != NULL) && (root2->child !=
                                           NULL))
            {
                if (root1->child->sibling == NULL)
                {
                    /*jika memiliki satu simpul anak*/
                    hasil =
                        isEqual(root1->child,
                                root2->child);
                }
                else
                {
                    /*jika memiliki banyak simpul
                    anak*/
                    simpul *bantu1 = root1->child;
                    simpul *bantu2 = root2->child;

                    while (bantu1->sibling !=
                           root1->child)
                    {
                        if ((bantu1 != NULL) && (bantu2 != NULL))
                        {
                            hasil =
                                isEqual(bantu1, bantu2);
                            bantu1 = bantu1->sibling;
                            bantu2 = bantu2->sibling;
                        }
                        else
                        {
                            hasil = 0;

                            break;
                        }
                    }
                    /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                    hasil = isEqual(bantu1, bantu2);
                }
            }
        }
    }
    else
    {
        if ((root1 != NULL) ||
            (root2 != NULL))
        {
            hasil = 0;
        }
    }
    return hasil;
}
int main()
{
    tree T;
    makeTree('A', &T);
    addChild('B', T.root);
    addChild('C', T.root);
    addChild('D', T.root);
    simpul *node =
        findSimpul('B', T.root);
    if (node != NULL)
    {
        addChild('E', node);
        addChild('F', node);
    }
    node = findSimpul('C', T.root);
    if (node != NULL)
    {
        addChild('G', node);
    }
    node = findSimpul('D', T.root);
    if (node != NULL)
    {
        addChild('H', node);
        addChild('I', node);
        addChild('J', node);
    }

    node = findSimpul('J', T.root);
    if (node != NULL)
    {
        addChild('K', node);
        addChild('L', node);
        addChild('M', node);
    }
    printf("=================\n");
    printf("preOrder\n");
    printTreePreOrder(T.root);
    printf("\n=================\n");
    printf("postOrder\n");
    printTreePostOrder(T.root);
    printf("\n=================\n");
    tree T2;
    copyTree(T.root, &T2.root);
    printTreePreOrder(T.root);
    printf("\n=================\n");
    printTreePreOrder(T2.root);
    printf("\n=================\n");
    if (isEqual(T.root, T2.root) == 1)
    {
        printf("pohon sama\n");
    }
    else
    {
        printf("pohon tidak sama\n");
    }

    node = findSimpul('J', T.root);
    if (node != NULL)
    {
        delChild('K', node);
        delChild('L', node);
        delChild('M', node);
    }
    printf("=================\n");
    printf("preOrder setelah dihapus\n");
    printTreePreOrder(T.root);
    printf("\n=================\n");

    return 0;
}