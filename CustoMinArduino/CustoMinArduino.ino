
#define MAX_ARRAY_SIZE 500


//Uma função de utilidade para imprimir o conteúdo de arr apos a ORDENAÇÂO para teste de corretude
void printArray(int *array, int size)
{
  for (int i = 0; i < size; i++) {
    Serial.print("  ");
    Serial.println(array[i]);
  }
  Serial.println();
}
/*----------------------------------------------------------FIM PRINT ARRAY-----------------------------------------------------------------------------------------*/

//Uma função de utilidade para trocar dois elementos
void swap(int *a, int *b)
{
  //Serial.println(" SWAB");
  int t = *a;
  *a = *b;
  *b = t;
}

//metodo quick interativo
int partition(int arr[], int indice_inicial, int indice_final)
{
  //Serial.println(" PARTITION");
  int x = arr[indice_final];
  int i = (indice_inicial - 1);

  for (int j = indice_inicial; j <= indice_final - 1; j++)
  {
    if (arr[j] >= x)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[indice_final]);
  return (i + 1);

}


//A [] -> Array a ser classificado,
// indice_inicial -> Índice inicial,
//indice_final -> Índice final * /
void quickSort(int arr[], int size)
{
  Serial.println(" QUICKSORT");
  int stack[MAX_ARRAY_SIZE];
  int top = -1;
  int indice_inicial = 0;
  int indice_final = size - 1;
  //empurre os valores iniciais de indice_inicial e indice_final para empilhar
  stack[++top] = indice_inicial;
  stack[++top] = indice_final;

  // Continue saindo da pilha enquanto não estiver vazio
  while (top >= 0)
  {
    indice_final = stack[top--];
    indice_inicial = stack[top--];

    // Defina o elemento pivô em sua posição correta
    // na matriz classificada
    int p = partition(arr, indice_inicial, indice_final);

    // Se houver elementos no lado esquerdo do pivô,
    // então empurre o lado esquerdo para empilhar
    if (p - 1 > indice_inicial)
    {
      stack[++top] = indice_inicial;
      stack[++top] = p - 1;
    }

    // Se houver elementos no lado direito do pivô,
    // então empurre o lado direito para empilhar
    if (p + 1 < indice_final)
    {
      stack[++top] = p + 1;
      stack[++top] = indice_final;
    }
  }
  Serial.println(" FIM QUICKSORT");
}

/*--------------------------------------------------------------------FIM QUICKSORT-------------------------------------------------------------------*/

//joga o maior elemento para o final da fila
//armazena a fila final de resultado
// O(n)
void pushSorted(int element, int *array, int *size)
{
  for (int i = 0; i < *size; i++)
  {
    if (element >= array[i])
    {
      swap(&array[i], &element);
    }
  }
  array[*size] = element;
  *size += 1;
}

//Tempo constante de levar o maior elemento para o final da fila 
long int pop(int *array, int *size)
{
  int last = array[*size - 1];
  *size -= 1;
  return last;
}

// O(n^2)
long int minCost(int *array, int size)
{
  long int cost = 0;

  quickSort(array, size); // O(n*log(n))
  //imprime o vetor apos a ordenação, ajuda a verificar se esta pronto para a soma de custo minimo
  printArray(array, size);

  //imprimindo o custo gerado de cada conexão por nó
  Serial.println("Resultado de cada custo por conexao: ");

  while (size > 1)
  {
    int first = pop(array, &size); //O(1)
    int second = pop(array, &size); //O(1)
    long int result = first + second;
    Serial.print("  ");
    Serial.print(result);
    cost += result;
    pushSorted(result, array, &size); // O(n)
  }

  return cost;
}


void setup()
{
  Serial.begin(9600);
//<------------------------------------------------- LISTAS PARA TESTES  --------------------------------------------------------------------->
  /*int test1000[] = {813, 484, 729, 904, 156, 493, 935, 850, 878, 600, 628, 957, 251, 588, 421, 56, 260, 20, 801, 933, 741, 805, 266, 2, 966, 973, 169, 754, 94, 576, 402, 193, 917, 687, 637, 161, 829, 910, 958, 19, 857, 33, 496, 959, 714, 409, 391, 201, 541, 136, 320, 580, 298, 276, 305, 388, 378, 702, 875, 717, 919, 579, 49, 267, 555, 39, 690, 287, 500, 315, 462, 771, 229, 284, 47, 297, 821, 490, 718, 721, 552, 5, 451, 226, 7, 306, 557, 879, 259, 695, 570, 110, 512, 781, 356, 130, 811, 710, 144, 448, 197, 751, 755, 738, 383, 896, 221, 252, 211, 501, 341, 319, 281, 246, 476, 296, 28, 817, 37, 278, 814, 540, 616, 920, 518, 792, 906, 472, 248, 111, 51, 513, 188, 543, 225, 880, 525, 423, 689, 596, 491, 467, 961, 657, 334, 435, 631, 275, 788, 761, 972, 105, 848, 430, 399, 425, 948, 487, 668, 554, 607, 982, 481, 1, 505, 207, 357, 327, 92, 669, 79, 575, 302, 808, 363, 340, 639, 314, 612, 41, 968, 57, 845, 178, 346, 273, 163, 941, 153, 943, 854, 285, 192, 595, 69, 81, 820, 609, 404, 550, 883, 241, 749, 937, 812, 533, 418, 233, 210, 84, 396, 985, 712, 191, 796, 258, 672, 245, 648, 561, 424, 674, 826, 715, 370, 339, 642, 782, 858, 744, 828, 46, 288, 403, 204, 29, 768, 303, 658, 842, 530, 528, 659, 696, 182, 832, 373, 997, 466, 408, 352, 841, 308, 386, 168, 509, 711, 885, 353, 148, 936, 479, 891, 118, 685, 810, 954, 128, 694, 101, 488, 799, 655, 264, 450, 922, 992, 914, 553, 117, 64, 902, 433, 231, 794, 526, 739, 376, 950, 748, 515, 994, 166, 934, 478, 124, 876, 565, 733, 437, 691, 381, 444, 856, 874, 271, 237, 257, 336, 773, 497, 640, 87, 746, 247, 131, 442, 307, 679, 394, 556, 819, 665, 915, 360, 313, 834, 224, 615, 772, 643, 823, 194, 382, 800, 244, 104, 802, 436, 653, 760, 913, 469, 385, 544, 150, 752, 398, 361, 24, 147, 389, 215, 641, 862, 317, 618, 337, 300, 223, 521, 671, 30, 410, 577, 495, 503, 282, 125, 73, 137, 921, 108, 38, 76, 78, 955, 510, 427, 887, 417, 97, 722, 944, 426, 190, 952, 195, 98, 762, 538, 698, 311, 34, 323, 686, 325, 831, 322, 31, 61, 929, 441, 865, 578, 42, 545, 189, 507, 535, 732, 598, 397, 175, 96, 445, 422, 766, 32, 522, 355, 682, 54, 825, 492, 348, 734, 60, 911, 871, 704, 377, 48, 90, 286, 40, 43, 990, 908, 458, 477, 295, 979, 463, 938, 429, 390, 170, 375, 269, 907, 886, 145, 387, 927, 9, 228, 680, 569, 605, 440, 991, 459, 791, 558, 847, 242, 213, 205, 532, 14, 939, 745, 843, 524, 888, 597, 502, 844, 159, 863, 239, 460, 534, 708, 102, 899, 155, 884, 452, 835, 870, 263,
                    895, 489, 333, 542, 656, 301, 975, 455, 795, 867, 380, 798, 940, 967, 932, 836, 316, 504, 962, 617, 837, 893, 294, 149, 784, 26, 587, 486, 560, 839, 765, 254, 120, 174, 551, 684, 351, 604, 840, 335, 343, 898, 621, 485, 328, 164, 167, 63, 633, 677, 724, 849, 126, 923, 293, 449, 649, 517, 240, 71, 606, 548, 359, 312, 783, 419, 369, 901, 83, 70, 185, 774, 608, 667, 172, 894, 498, 220, 176, 53, 99, 753, 67, 692, 666, 439, 996, 160, 143, 432, 299, 55, 806, 516, 592, 654, 25, 4, 456, 199, 52, 206, 446, 645, 873, 519, 232, 141, 219, 35, 978, 8, 133, 585, 594, 473, 480, 945, 372, 234, 660, 905, 22, 881, 727, 332, 619, 291, 412, 706, 428, 326, 625, 146, 963, 701, 897, 790, 12, 916, 415, 89, 154, 345, 539, 367, 777, 931, 88, 238, 900, 869, 277, 947, 852, 227, 946, 374, 347, 593, 531, 272, 750, 591, 465, 623, 243, 420, 165, 123, 354, 599, 892, 384, 85, 736, 986, 953, 758, 824, 413, 675, 786, 763, 474, 27, 980, 664, 321, 59, 924, 636, 216, 735, 890, 520, 331, 872, 626, 779, 309, 676, 113, 162, 414, 177, 0, 405, 918, 951, 634, 135, 62, 45, 809, 499, 949, 280, 310, 304, 903, 431, 635, 235, 115, 262, 443, 158, 960, 371, 703, 392, 572, 457, 803, 981, 759, 622, 253, 590, 364, 581, 567, 58, 976, 693, 350, 358, 17, 603, 114, 571, 787, 912, 173, 566, 50, 140, 91, 970, 816, 109, 222, 44, 180, 707, 846, 36, 330, 464, 208, 470, 775, 106, 613, 740, 984, 400, 407, 368, 719, 559, 838, 815, 529, 198, 68, 673, 406, 868, 134, 767, 290, 121, 807, 152, 112, 804, 974, 644, 650, 77, 179, 909, 851, 434, 547, 861, 3, 620, 527, 731, 661, 200, 202, 362, 964, 139, 249, 574, 866, 723, 646, 289, 663, 546, 324, 265, 564, 989, 993, 589, 80, 632, 196, 438, 483, 662, 184, 142, 13, 65, 127, 652, 651, 86, 602, 586, 475, 132, 183, 956, 453, 344, 93, 928, 482, 769, 329, 283, 186, 827, 614, 969, 629, 568, 930, 116, 338, 447, 780, 537, 255, 523, 822, 209, 72, 855, 236, 256, 107, 292, 16, 23, 726, 95, 454, 678, 995, 647, 610, 725, 279, 720, 573, 75, 270, 549, 250, 536, 864, 66, 728, 10, 514, 688, 860, 859, 230, 511, 705, 925, 983, 737, 582, 697, 6, 100, 103, 365, 818, 218, 630, 21, 203, 82, 349, 379, 562, 181, 494, 318, 778, 583, 977, 942, 926, 411, 683, 611, 138, 833, 853, 627, 770, 151, 563, 988, 681, 730, 965, 987, 793, 274, 416, 998, 776, 601, 187, 709, 401, 461, 74, 395, 700, 713, 129, 757, 889, 18, 742, 830, 122, 756, 268, 789, 171, 747, 670, 393, 212, 214, 217, 624, 342, 785, 716, 877, 157, 764, 508, 506, 882, 468, 11, 471, 366, 971, 584, 261, 699, 638, 15, 119, 743, 797
                   };*/

  /*int test900[] = {168, 226, 348, 234, 824, 855, 647, 844, 445, 325, 184, 727, 827, 241, 38, 542, 416, 702, 440, 549, 255, 657, 53, 869, 567, 402, 67, 885, 628, 483, 153, 364, 436, 813, 662, 537, 358, 102, 145, 530, 84, 842, 587, 896, 263, 74, 220, 254, 575, 253, 666, 321, 400, 546, 593, 840, 117, 675, 289, 121, 826, 146, 463, 586, 807, 853, 351, 399, 650, 835, 3, 106, 588, 24, 310, 429, 686, 645, 615, 616, 269, 424, 721, 363, 180, 20, 242, 838, 13, 731, 170, 162, 892, 831, 359, 412, 805, 781, 297, 464, 764, 589, 96, 125, 579, 326, 108, 761, 372, 379, 383, 320, 174, 273, 671, 876, 500, 651, 248, 334, 337, 453, 442, 812, 401, 70, 407, 772, 520, 541, 507, 808, 92, 374, 866, 577, 526, 742, 691, 884, 415, 534, 353, 22, 417, 867, 833, 60, 768, 425, 787, 527, 191, 572, 456, 690, 681, 333, 722, 185, 695, 132, 270, 420, 665, 791, 639, 897, 564, 340, 212, 443, 66, 850, 509, 785, 836, 86, 540, 157, 684, 595, 770, 502, 42, 760, 670, 148, 597, 437, 484, 18, 495, 299, 64, 814, 423, 7, 825, 468, 809, 652, 883, 705, 0, 314, 698, 28, 294, 171, 55, 279, 346, 288, 799, 118, 642, 806, 535, 712, 215, 663, 147, 485, 216, 525, 160, 738, 258, 338, 207, 295, 204, 697, 201, 116, 560, 654, 418, 433, 777, 550, 517, 821, 629, 434, 111, 504, 682, 769, 58, 797, 623, 475, 736, 477, 54, 688, 820, 397, 519, 810, 370, 751, 846, 496, 59, 427, 693, 719, 522, 413, 135, 377, 283, 229, 505, 544, 755, 408, 873, 570, 328, 499, 177, 199, 711, 536, 141, 625, 194, 490, 664, 257, 790, 573, 803, 871, 609, 582, 307, 136, 430, 450, 208, 828, 621, 261, 411, 316, 881, 843, 82, 345, 389, 703, 788, 302, 740, 247, 154, 816, 43, 627, 655, 195, 285, 164, 538, 489, 94, 857, 669, 633, 331, 291, 563, 249, 439, 674, 252, 778, 272, 239, 638, 878, 875, 848, 865, 724, 101, 23, 119, 605, 773, 384, 161, 789, 795, 554, 734, 278, 454, 837, 776, 531, 124, 130, 48, 891, 895, 282, 225, 71, 138, 182, 200, 543, 849, 5, 371, 29, 16, 349, 545, 565, 845, 172, 183, 879, 528, 709, 602, 600, 398, 859, 394, 304, 221, 804, 725, 47, 39, 202, 173, 556, 166, 739, 508, 95, 312, 473, 660, 134, 87, 83, 512, 510, 745, 753, 365, 142, 149, 792, 224, 375, 894, 775, 217, 733, 167, 428, 877, 419, 598, 626, 432, 305, 290, 592, 4, 354, 532, 392, 343, 851, 446, 744, 105, 610, 758, 841, 406, 264, 679, 622, 608, 890, 203, 762, 292, 378, 815, 700, 210, 187, 637, 858, 27, 75, 458, 566, 521, 466, 262, 494, 293, 386, 863, 718, 335, 661, 237, 40, 190, 369, 235, 165, 765, 52, 714, 85, 707, 465, 802, 648, 581, 498, 137, 870, 800, 275, 636, 281,
                   143, 551, 749, 68, 763, 687, 10, 387, 720, 619, 868, 232, 128, 673, 2, 311, 218, 578, 796, 186, 188, 355, 21, 631, 476, 236, 782, 178, 32, 452, 611, 710, 694, 646, 198, 747, 634, 277, 447, 97, 659, 539, 309, 715, 391, 643, 227, 601, 672, 140, 197, 373, 783, 72, 754, 811, 76, 344, 25, 240, 319, 313, 17, 482, 213, 34, 308, 41, 169, 152, 284, 864, 350, 107, 14, 817, 80, 410, 562, 51, 729, 139, 243, 856, 382, 1, 701, 435, 613, 112, 251, 405, 585, 414, 45, 388, 774, 748, 448, 209, 590, 474, 69, 607, 580, 151, 553, 759, 362, 472, 614, 426, 230, 114, 196, 36, 155, 854, 79, 716, 274, 78, 667, 144, 683, 862, 8, 380, 120, 318, 122, 594, 327, 658, 256, 732, 728, 457, 422, 516, 574, 57, 479, 206, 77, 839, 126, 668, 737, 158, 503, 271, 830, 421, 469, 19, 882, 9, 478, 127, 46, 176, 181, 596, 267, 606, 306, 548, 889, 163, 323, 888, 708, 750, 49, 680, 497, 360, 93, 56, 872, 451, 156, 779, 455, 462, 193, 569, 409, 396, 591, 315, 493, 330, 81, 431, 444, 113, 689, 576, 12, 793, 65, 860, 632, 571, 617, 756, 635, 887, 150, 233, 361, 368, 514, 341, 403, 265, 276, 98, 583, 618, 366, 552, 874, 301, 678, 713, 339, 449, 743, 189, 332, 231, 511, 644, 33, 834, 381, 133, 228, 523, 15, 481, 99, 266, 829, 300, 603, 259, 317, 175, 649, 214, 336, 280, 513, 347, 441, 723, 557, 653, 529, 393, 620, 470, 287, 376, 801, 886, 784, 832, 491, 584, 438, 822, 641, 50, 244, 741, 89, 704, 823, 488, 219, 780, 604, 486, 44, 390, 735, 547, 110, 395, 899, 676, 222, 558, 752, 324, 129, 630, 898, 123, 296, 62, 861, 461, 109, 303, 786, 847, 726, 818, 268, 30, 561, 26, 367, 322, 131, 245, 238, 640, 717, 692, 104, 685, 794, 819, 559, 250, 37, 342, 518, 329, 467, 471, 35, 63, 798, 31, 103, 656, 286, 459, 515, 696, 91, 699, 100, 880, 90, 115, 487, 746, 852, 6, 568, 771, 555, 599, 385, 211, 757, 893, 298, 352, 404, 730, 612, 460, 357, 223, 11, 246, 677, 179, 159, 501, 205, 533, 706, 356, 506, 88, 73, 766, 624, 260, 61, 192, 480, 492, 524, 767
                  };*/

  //int test500[] = {185, 57, 424, 104, 9, 66, 323, 69, 385, 4, 180, 26, 184, 167, 202, 319, 293, 140, 242, 231, 120, 334, 452, 274, 234, 267, 77, 171, 313, 290, 486, 265, 154, 56, 359, 454, 215, 209, 248, 371, 332, 401, 39, 61, 419, 479, 119, 291, 76, 235, 462, 223, 189, 382, 389, 489, 44, 239, 463, 447, 72, 455, 109, 175, 348, 377, 376, 48, 289, 335, 73, 43, 137, 212, 160, 394, 188, 130, 60, 105, 415, 294, 199, 420, 474, 484, 78, 6, 63, 54, 378, 427, 55, 116, 99, 224, 226, 308, 37, 205, 41, 288, 91, 53, 342, 418, 365, 485, 186, 106, 358, 17, 470, 31, 422, 64, 276, 398, 201, 402, 94, 280, 311, 350, 143, 51, 441, 449, 233, 97, 383, 87, 360, 82, 271, 62, 434, 2, 408, 386, 317, 19, 183, 142, 150, 74, 473, 246, 438, 194, 211, 425, 229, 214, 25, 203, 281, 433, 30, 314, 165, 100, 409, 417, 362, 86, 478, 11, 286, 471, 176, 196, 21, 330, 493, 373, 58, 227, 65, 426, 206, 36, 266, 216, 331, 254, 397, 197, 393, 172, 354, 421, 85, 177, 251, 292, 297, 279, 344, 75, 483, 459, 40, 24, 96, 352, 108, 316, 465, 241, 369, 435, 333, 472, 437, 15, 79, 118, 101, 468, 263, 367, 310, 152, 0, 428, 482, 328, 219, 32, 164, 355, 273, 182, 458, 490, 453, 159, 464, 356, 303, 220, 52, 460, 495, 112, 364, 336, 340, 139, 33, 349, 243, 59, 405, 392, 133, 494, 83, 456, 111, 50, 347, 193, 123, 192, 403, 430, 399, 173, 244, 13, 284, 326, 416, 307, 498, 204, 124, 315, 461, 391, 278, 366, 322, 238, 436, 46, 380, 379, 309, 190, 275, 236, 68, 338, 259, 7, 450, 163, 375, 3, 161, 370, 200, 125, 282, 49, 191, 300, 396, 92, 361, 158, 318, 253, 268, 81, 93, 147, 28, 302, 270, 149, 153, 258, 374, 400, 444, 467, 128, 222, 240, 98, 129, 195, 20, 237, 218, 384, 283, 166, 487, 445, 156, 107, 141, 174, 451, 114, 372, 14, 410, 411, 305, 29, 90, 247, 10, 8, 329, 210, 324, 387, 162, 155, 264, 245, 446, 181, 34, 406, 388, 339, 287, 138, 499, 257, 71, 321, 301, 432, 256, 260, 491, 151, 320, 22, 443, 16, 414, 47, 187, 117, 230, 306, 353, 448, 325, 70, 272, 413, 221, 357, 225, 466, 390, 429, 480, 126, 178, 492, 18, 88, 84, 42, 395, 207, 168, 12, 341, 228, 343, 252, 327, 496, 134, 5, 269, 469, 103, 170, 169, 476, 27, 179, 312, 250, 122, 404, 299, 132, 102, 439, 131, 346, 285, 412, 368, 127, 213, 145, 249, 295, 136, 481, 115, 488, 198, 262, 80, 381, 475, 208, 144, 95, 440, 255, 351, 345, 442, 363, 113, 121, 407, 337, 135, 148, 35, 1, 67, 45, 298, 157, 477, 497, 423, 457, 304, 217, 296, 232, 146, 38, 261, 277, 23, 110, 89, 431};

  //int test200[] = {108, 86, 174, 3, 23, 143, 88, 129, 26, 160, 159, 78, 80, 168, 147, 76, 152, 113, 25, 121, 136, 110, 12, 94, 101, 41, 46, 97, 189, 36, 191, 106, 187, 186, 142, 190, 163, 81, 49, 71, 62, 43, 169, 183, 197, 176, 32, 105, 19, 22, 140, 115, 193, 95, 175, 137, 50, 156, 40, 127, 120, 37, 70, 61, 182, 102, 114, 9, 10, 122, 33, 39, 185, 34, 92, 179, 73, 123, 20, 60, 56, 38, 149, 52, 107, 111, 164, 67, 124, 192, 146, 66, 55, 5, 69, 8, 29, 158, 198, 125, 134, 64, 42, 161, 199, 18, 103, 59, 138, 100, 75, 119, 90, 135, 51, 172, 141, 150, 144, 77, 63, 89, 28, 130, 117, 93, 112, 132, 17, 15, 45, 1, 72, 30, 155, 188, 47, 139, 4, 148, 153, 82, 96, 133, 151, 131, 16, 74, 48, 14, 181, 109, 171, 35, 58, 87, 21, 65, 84, 184, 85, 27, 165, 6, 91, 11, 104, 162, 194, 24, 31, 173, 54, 178, 98, 68, 145, 128, 57, 154, 195, 13, 118, 44, 2, 53, 167, 170, 126, 177, 180, 7, 157, 99, 79, 196, 116, 83, 0, 166};
  int test300[] = {78, 270, 184, 12, 204, 287, 154, 299, 281, 263, 218, 51, 9, 92, 119, 151, 60, 72, 75, 104, 196, 273, 224, 165, 71, 8, 124, 137, 216, 241, 109, 50, 213, 84, 274, 56, 175, 103, 30, 74, 6, 148, 159, 250, 291, 35, 59, 194, 20, 44, 288, 113, 82, 106, 58, 285, 144, 271, 160, 193, 38, 90, 79, 45, 191, 245, 166, 168, 222, 215, 136, 11, 39, 49, 118, 152, 195, 210, 228, 235, 55, 4, 77, 129, 34, 220, 63, 110, 128, 297, 187, 295, 115, 141, 247, 125, 24, 76, 260, 150, 217, 7, 142, 211, 52, 61, 182, 102, 173, 283, 171, 294, 178, 65, 257, 93, 251, 231, 282, 101, 162, 279, 272, 25, 278, 17, 64, 284, 46, 261, 225, 42, 81, 226, 176, 180, 3, 123, 54, 265, 264, 266, 13, 146, 120, 135, 232, 198, 105, 237, 111, 253, 47, 83, 48, 18, 40, 163, 205, 234, 147, 132, 212, 203, 62, 70, 230, 201, 67, 293, 248, 244, 19, 174, 134, 280, 100, 223, 138, 239, 164, 255, 143, 276, 86, 68, 66, 69, 277, 95, 161, 41, 28, 21, 298, 158, 153, 207, 199, 236, 221, 53, 219, 172, 170, 206, 229, 256, 16, 36, 179, 89, 140, 246, 96, 145, 33, 80, 15, 26, 114, 133, 97, 268, 127, 157, 267, 238, 169, 233, 126, 275, 149, 177, 122, 254, 43, 107, 290, 292, 73, 22, 139, 190, 29, 269, 243, 189, 108, 32, 289, 197, 121, 227, 242, 130, 258, 240, 91, 57, 259, 167, 1, 37, 0, 131, 14, 2, 183, 200, 202, 208, 5, 192, 156, 27, 214, 112, 10, 117, 188, 286, 296, 85, 87, 88, 23, 181, 94, 262, 249, 155, 99, 98, 252, 185, 209, 186, 31, 116};
  //int test3[] = {4544, 2343, 8342, 2347, 1230};
  //int testinit[] = {56, 4, 3, 2, 6, 7, 12, 100, 101, 103, 77, 34};
//<----------------------------------------------------------------------------------------------------------------------------------------------->
  
  long int size = 300;
  long int result = minCost(test300, size);      //test2000 //testinit

  Serial.println();
  Serial.print(F("Resultado de custo total: "));
  Serial.print(result);

}

void loop() {
  //
}
