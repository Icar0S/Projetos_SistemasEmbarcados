//Uma função de utilidade para imprimir o conteúdo de arr apos a ORDENAÇÂO para teste de corretude
/*void printArray(int *array, int size)
  {
  for (int i = 0; i < size; i++) {
    Serial.print("  ");
    Serial.print(array[i]);
  }
  Serial.println();
  }*/

//--------------------------------------------------------------TESTE ARRAYS------------------------------------------------------------------------

int test900[] = { 286, 857, 672, 290, 124, 162, 879, 362, 848, 703, 775, 35, 227, 202, 488, 258, 188, 129, 71, 118, 363, 342, 68, 707, 414, 60, 471, 668, 332, 534, 117, 194, 169, 412, 135, 669, 78, 407, 452, 431, 447, 617, 605, 818, 464, 762, 553, 48, 787, 883, 643, 704, 27, 556, 824, 347, 409, 539, 689, 152, 83, 359, 615, 413, 874, 661, 282, 895, 357, 675, 825, 662, 301, 30, 195, 711, 142, 878, 320, 640, 487, 717, 564, 205, 579, 356, 204, 533, 502, 337, 543, 443, 593, 140, 314, 263, 851, 257, 451, 499, 656, 114, 515, 150, 322, 583, 485, 375, 706, 627, 696, 442, 558, 335, 597, 819, 859, 832, 636, 537, 400, 528, 382, 489, 224, 624, 348, 98, 36, 844, 115, 650, 327, 367, 291, 619, 453, 116, 807, 551, 95, 576, 776, 54, 232, 429, 713, 1, 173, 765, 89, 886, 403, 771, 246, 52, 761, 369, 606, 718, 139, 241, 268, 494, 683, 847, 560, 86, 816, 784, 524, 323, 527, 99, 695, 592, 602, 644, 222, 49, 708, 440, 468, 404, 691, 759, 329, 625, 777, 378, 415, 743, 285, 809, 163, 888, 47, 101, 740, 44, 120, 637, 792, 574, 82, 259, 697, 562, 100, 333, 867, 842, 157, 298, 690, 393, 425, 339, 132, 630, 712, 121, 836, 739, 123, 571, 492, 88, 642, 766, 865, 389, 885, 185, 588, 573, 788, 785, 317, 336, 390, 701, 441, 737, 827, 497, 5, 351, 67, 522, 608, 377, 823, 596, 480, 871, 632, 542, 728, 509, 811, 446, 213, 742, 361, 506, 176, 295, 344, 744, 177, 684, 136, 191, 493, 266, 752, 13, 484, 236, 130, 694, 181, 391, 239, 18, 821, 180, 81, 474, 418, 714, 705, 45, 628, 459, 595, 292, 793, 206, 41, 620, 577, 6, 171, 449, 893, 125, 104, 651, 747, 16, 170, 343, 598, 882, 794, 26, 503, 840, 810, 899, 242, 111, 567, 408, 211, 864, 368, 555, 62, 601, 97, 520, 837, 353, 749, 623, 631, 270, 526, 645, 779, 604, 773, 626, 126, 757, 535, 79, 655, 545, 530, 249, 372, 305, 309, 698, 546, 799, 220, 208, 727, 417, 119, 398, 299, 892, 460, 880, 721, 456, 64, 802, 349, 679, 73, 423, 138, 63, 831, 516, 445, 345, 828, 174, 160, 808, 262, 141, 9, 658, 729, 91, 70, 156, 113, 795, 8, 175, 269, 758, 833, 889, 405, 379, 252, 411, 839, 271, 685, 682, 513, 852, 225, 455, 151, 469, 350, 155, 102, 76, 829, 210, 653, 664, 439, 235, 280, 479, 512, 72, 518, 187, 614, 594, 756, 33, 548, 563, 300, 586, 230, 216, 613, 609, 380, 318, 541, 549, 566, 817, 843, 245, 470, 812, 410, 281, 21, 310, 612, 178, 667, 659, 845, 866, 277, 432, 12, 325, 370, 666, 399, 2, 876, 467, 69, 108, 850, 22, 29, 629, 193, 321, 338, 599, 279, 500, 172, 600,
                  77, 511, 199, 517, 783, 430, 55, 96, 569, 699, 763, 496, 422, 395, 31, 128, 575, 214, 200, 87, 308, 800, 770, 798, 674, 531, 448, 127, 676, 50, 670, 521, 681, 437, 677, 226, 219, 454, 868, 861, 647, 207, 186, 34, 402, 607, 131, 122, 547, 46, 665, 331, 233, 144, 589, 435, 796, 147, 307, 289, 890, 229, 354, 611, 835, 438, 93, 764, 472, 525, 4, 748, 720, 364, 164, 161, 841, 167, 75, 753, 815, 84, 581, 416, 212, 386, 881, 273, 179, 481, 250, 491, 726, 838, 385, 618, 734, 660, 680, 311, 294, 65, 501, 830, 715, 781, 725, 780, 426, 693, 722, 462, 383, 105, 387, 875, 738, 42, 376, 23, 891, 457, 834, 570, 182, 898, 303, 550, 384, 508, 276, 253, 582, 638, 0, 803, 315, 873, 406, 10, 165, 654, 56, 366, 218, 519, 723, 11, 862, 154, 870, 495, 774, 360, 371, 475, 587, 278, 584, 745, 544, 313, 746, 805, 741, 686, 59, 109, 106, 94, 616, 306, 189, 297, 678, 324, 482, 858, 663, 32, 463, 692, 392, 264, 673, 394, 238, 732, 43, 465, 755, 724, 536, 702, 585, 217, 58, 877, 856, 110, 143, 801, 633, 716, 288, 149, 243, 750, 778, 25, 710, 538, 887, 648, 894, 228, 760, 340, 504, 510, 444, 251, 283, 804, 700, 7, 20, 198, 854, 267, 434, 477, 789, 221, 287, 634, 92, 19, 649, 709, 565, 358, 274, 532, 731, 90, 272, 490, 201, 61, 769, 719, 334, 248, 24, 420, 557, 275, 523, 397, 860, 736, 450, 28, 133, 733, 791, 652, 498, 355, 183, 14, 473, 203, 419, 806, 134, 505, 869, 561, 66, 849, 671, 540, 296, 326, 603, 137, 797, 388, 507, 813, 196, 352, 514, 730, 51, 580, 237, 768, 433, 554, 428, 40, 635, 688, 872, 316, 427, 476, 365, 846, 855, 254, 401, 346, 751, 145, 373, 148, 436, 153, 304, 37, 767, 284, 820, 197, 822, 265, 424, 853, 578, 17, 57, 786, 85, 641, 772, 107, 461, 552, 610, 568, 687, 341, 74, 302, 814, 260, 209, 735, 478, 590, 754, 572, 826, 458, 190, 39, 486, 790, 261, 15, 184, 223, 112, 256, 591, 231, 646, 466, 782, 319, 38, 312, 863, 396, 166, 621, 421, 483, 103, 639, 240, 293, 657, 374, 192, 896, 884, 80, 53, 897, 328, 215, 247, 158, 244, 3, 330, 234, 168, 255, 622, 529, 146, 159, 381, 559
                };

//int test500[] = {185, 57, 424, 104, 9, 66, 323, 69, 385, 4, 180, 26, 184, 167, 202, 319, 293, 140, 242, 231, 120, 334, 452, 274, 234, 267, 77, 171, 313, 290, 486, 265, 154, 56, 359, 454, 215, 209, 248, 371, 332, 401, 39, 61, 419, 479, 119, 291, 76, 235, 462, 223, 189, 382, 389, 489, 44, 239, 463, 447, 72, 455, 109, 175, 348, 377, 376, 48, 289, 335, 73, 43, 137, 212, 160, 394, 188, 130, 60, 105, 415, 294, 199, 420, 474, 484, 78, 6, 63, 54, 378, 427, 55, 116, 99, 224, 226, 308, 37, 205, 41, 288, 91, 53, 342, 418, 365, 485, 186, 106, 358, 17, 470, 31, 422, 64, 276, 398, 201, 402, 94, 280, 311, 350, 143, 51, 441, 449, 233, 97, 383, 87, 360, 82, 271, 62, 434, 2, 408, 386, 317, 19, 183, 142, 150, 74, 473, 246, 438, 194, 211, 425, 229, 214, 25, 203, 281, 433, 30, 314, 165, 100, 409, 417, 362, 86, 478, 11, 286, 471, 176, 196, 21, 330, 493, 373, 58, 227, 65, 426, 206, 36, 266, 216, 331, 254, 397, 197, 393, 172, 354, 421, 85, 177, 251, 292, 297, 279, 344, 75, 483, 459, 40, 24, 96, 352, 108, 316, 465, 241, 369, 435, 333, 472, 437, 15, 79, 118, 101, 468, 263, 367, 310, 152, 0, 428, 482, 328, 219, 32, 164, 355, 273, 182, 458, 490, 453, 159, 464, 356, 303, 220, 52, 460, 495, 112, 364, 336, 340, 139, 33, 349, 243, 59, 405, 392, 133, 494, 83, 456, 111, 50, 347, 193, 123, 192, 403, 430, 399, 173, 244, 13, 284, 326, 416, 307, 498, 204, 124, 315, 461, 391, 278, 366, 322, 238, 436, 46, 380, 379, 309, 190, 275, 236, 68, 338, 259, 7, 450, 163, 375, 3, 161, 370, 200, 125, 282, 49, 191, 300, 396, 92, 361, 158, 318, 253, 268, 81, 93, 147, 28, 302, 270, 149, 153, 258, 374, 400, 444, 467, 128, 222, 240, 98, 129, 195, 20, 237, 218, 384, 283, 166, 487, 445, 156, 107, 141, 174, 451, 114, 372, 14, 410, 411, 305, 29, 90, 247, 10, 8, 329, 210, 324, 387, 162, 155, 264, 245, 446, 181, 34, 406, 388, 339, 287, 138, 499, 257, 71, 321, 301, 432, 256, 260, 491, 151, 320, 22, 443, 16, 414, 47, 187, 117, 230, 306, 353, 448, 325, 70, 272, 413, 221, 357, 225, 466, 390, 429, 480, 126, 178, 492, 18, 88, 84, 42, 395, 207, 168, 12, 341, 228, 343, 252, 327, 496, 134, 5, 269, 469, 103, 170, 169, 476, 27, 179, 312, 250, 122, 404, 299, 132, 102, 439, 131, 346, 285, 412, 368, 127, 213, 145, 249, 295, 136, 481, 115, 488, 198, 262, 80, 381, 475, 208, 144, 95, 440, 255, 351, 345, 442, 363, 113, 121, 407, 337, 135, 148, 35, 1, 67, 45, 298, 157, 477, 497, 423, 457, 304, 217, 296, 232, 146, 38, 261, 277, 23, 110, 89, 431};

//int test300[] = {78, 270, 184, 12, 204, 287, 154, 299, 281, 263, 218, 51, 9, 92, 119, 151, 60, 72, 75, 104, 196, 273, 224, 165, 71, 8, 124, 137, 216, 241, 109, 50, 213, 84, 274, 56, 175, 103, 30, 74, 6, 148, 159, 250, 291, 35, 59, 194, 20, 44, 288, 113, 82, 106, 58, 285, 144, 271, 160, 193, 38, 90, 79, 45, 191, 245, 166, 168, 222, 215, 136, 11, 39, 49, 118, 152, 195, 210, 228, 235, 55, 4, 77, 129, 34, 220, 63, 110, 128, 297, 187, 295, 115, 141, 247, 125, 24, 76, 260, 150, 217, 7, 142, 211, 52, 61, 182, 102, 173, 283, 171, 294, 178, 65, 257, 93, 251, 231, 282, 101, 162, 279, 272, 25, 278, 17, 64, 284, 46, 261, 225, 42, 81, 226, 176, 180, 3, 123, 54, 265, 264, 266, 13, 146, 120, 135, 232, 198, 105, 237, 111, 253, 47, 83, 48, 18, 40, 163, 205, 234, 147, 132, 212, 203, 62, 70, 230, 201, 67, 293, 248, 244, 19, 174, 134, 280, 100, 223, 138, 239, 164, 255, 143, 276, 86, 68, 66, 69, 277, 95, 161, 41, 28, 21, 298, 158, 153, 207, 199, 236, 221, 53, 219, 172, 170, 206, 229, 256, 16, 36, 179, 89, 140, 246, 96, 145, 33, 80, 15, 26, 114, 133, 97, 268, 127, 157, 267, 238, 169, 233, 126, 275, 149, 177, 122, 254, 43, 107, 290, 292, 73, 22, 139, 190, 29, 269, 243, 189, 108, 32, 289, 197, 121, 227, 242, 130, 258, 240, 91, 57, 259, 167, 1, 37, 0, 131, 14, 2, 183, 200, 202, 208, 5, 192, 156, 27, 214, 112, 10, 117, 188, 286, 296, 85, 87, 88, 23, 181, 94, 262, 249, 155, 99, 98, 252, 185, 209, 186, 31, 116};

//int test200[] = {108, 86, 174, 3, 23, 143, 88, 129, 26, 160, 159, 78, 80, 168, 147, 76, 152, 113, 25, 121, 136, 110, 12, 94, 101, 41, 46, 97, 189, 36, 191, 106, 187, 186, 142, 190, 163, 81, 49, 71, 62, 43, 169, 183, 197, 176, 32, 105, 19, 22, 140, 115, 193, 95, 175, 137, 50, 156, 40, 127, 120, 37, 70, 61, 182, 102, 114, 9, 10, 122, 33, 39, 185, 34, 92, 179, 73, 123, 20, 60, 56, 38, 149, 52, 107, 111, 164, 67, 124, 192, 146, 66, 55, 5, 69, 8, 29, 158, 198, 125, 134, 64, 42, 161, 199, 18, 103, 59, 138, 100, 75, 119, 90, 135, 51, 172, 141, 150, 144, 77, 63, 89, 28, 130, 117, 93, 112, 132, 17, 15, 45, 1, 72, 30, 155, 188, 47, 139, 4, 148, 153, 82, 96, 133, 151, 131, 16, 74, 48, 14, 181, 109, 171, 35, 58, 87, 21, 65, 84, 184, 85, 27, 165, 6, 91, 11, 104, 162, 194, 24, 31, 173, 54, 178, 98, 68, 145, 128, 57, 154, 195, 13, 118, 44, 2, 53, 167, 170, 126, 177, 180, 7, 157, 99, 79, 196, 116, 83, 0, 166};

//int test3[] = {4544, 2343, 8342, 2347, 1230};
//int testinit[] = {56, 4, 3, 2, 6, 7, 12, 100, 101, 103, 77, 34};
//int test4[] = {4, 3, 2, 6};

//--------------------------------------------------------------TESTE ARRAYS-------------------------------------------------------------------------

//Uma função de utilidade para trocar dois elementos
void swap(int *a, int *b)
{
  //Serial.println(" SWAB");
  int t = *a;
  *a = *b;
  *b = t;
}

void bubbleSort(int *arr , int tamSize)
{
  int k;
  int j;
  int aux;

  for (k = 1; k < tamSize; k++) {
    for (j = 0; j < tamSize - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        aux = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = aux;
      }
    }
  }
}


//--------------------------------------------------------------------FIM bubbleSort-------------------------------------------------------------------/

//joga o maior elemento para o final da fila
//armazena a fila final de resultado
// O(n)
void pushSorted(int element, int *array , int *tamSize)
{
  for (int i = 0; i < *tamSize; i++)
  {
    if (element >= array[i])
    {
      swap(&array[i], &element);
    }
  }
  array[*tamSize] = element;
  *tamSize += 1;
}

//Tempo constante de levar o maior para o final da fila  uint8_t uint16_t
uint32_t pop(int *array , int *tamSize )
{
  uint32_t last = array[*tamSize - 1];
  *tamSize -= 1;
  return last;
}

// O(n^2)
uint32_t minCost(int *array, int tamSize)
{
  uint32_t cost = 0;

  bubbleSort(array, tamSize);
  //printArray(array, tamSize);
  //Serial.println("Resultado de cada custo por conexao: ");
  while (tamSize > 1)
  {
    int first = pop(array, &tamSize); //O(1)
    int second = pop(array, &tamSize); //O(1)
    uint32_t result = first + second;
    //Serial.println(result);
    cost += result;
    pushSorted(result, array, &tamSize); // O(n)
  }

  return cost;
}




void setup()
{
  Serial.begin(9600);
  unsigned long timeBe = micros();
  uint32_t tamSize = 900;
  uint32_t result = minCost(test900, tamSize);
  //Serial.println(F(" Resultado de custo total:  "));
  Serial.println(result);
  unsigned long timeEn = micros();

  unsigned long duration = timeEn - timeBe;
  double durationT = (double)duration / 1000000.0;
 
  //imprime o tempo desde que o programa iniciou, em milissegundos
  Serial.print("Tempo:\n");
  Serial.println(durationT);

}

void loop() {
  //
}