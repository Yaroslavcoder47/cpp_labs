import cv2
import numpy as np
import matplotlib.pyplot as plt


def edge_detection_sobel(grayscale_img):
    sobelx = cv2.Sobel(grayscale_img, cv2.CV_64F, 1, 0, ksize=3)
    sobely = cv2.Sobel(grayscale_img, cv2.CV_64F, 0, 1, ksize=3)
    sobel_combined = cv2.addWeighted(cv2.convertScaleAbs(sobelx), 0.5, cv2.convertScaleAbs(sobely), 0.5, 0)
    return sobel_combined

def edge_detection_canny(grayscale_img, min_val=50, max_val=150):
    return cv2.Canny(grayscale_img, min_val, max_val)



def edge_detection_morphological_internal(binary_img, kernel_size=3):
    kernel = np.ones((kernel_size, kernel_size), np.uint8)
    erosion = cv2.erode(binary_img, kernel, iterations=1)
    return cv2.subtract(binary_img, erosion)

def edge_detection_morphological_standard(binary_img, kernel_size=3):
    kernel = np.ones((kernel_size, kernel_size), np.uint8)
    return cv2.morphologyEx(binary_img, cv2.MORPH_GRADIENT, kernel)



image_path = 'image.jpg'
grayscale_img = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)

if grayscale_img is None:
    print(f"Ошибка: Не удалось загрузить изображение по пути: {image_path}. Проверьте путь.")
else:
    _, binary_img = cv2.threshold(grayscale_img, 127, 255, cv2.THRESH_BINARY)
    
    # ВЫДЕЛЕНИЕ ГРАНИЦ НА ПОЛУТОНОВОМ
    edges_sobel = edge_detection_sobel(grayscale_img)
    edges_canny = edge_detection_canny(grayscale_img)
    
    # ВЫДЕЛЕНИЕ ГРАНИЦ НА БИНАРНОМ
    edges_morph_internal = edge_detection_morphological_internal(binary_img)
    edges_morph_standard = edge_detection_morphological_standard(binary_img)

    fig, axes = plt.subplots(2, 3, figsize=(15, 8))

    axes[0, 0].imshow(grayscale_img, cmap='gray'); axes[0, 0].set_title('Исходное')
    axes[0, 1].imshow(edges_sobel, cmap='gray'); axes[0, 1].set_title('Границы Собеля')
    axes[0, 2].imshow(edges_canny, cmap='gray'); axes[0, 2].set_title('Границы Кэнни')
    
    axes[1, 0].imshow(binary_img, cmap='gray'); axes[1, 0].set_title('Исходное')
    axes[1, 1].imshow(edges_morph_internal, cmap='gray'); axes[1, 1].set_title('Морфологический (Внутренний)')
    axes[1, 2].imshow(edges_morph_standard, cmap='gray'); axes[1, 2].set_title('Морфологический (Стандартный)')
    
    for ax in axes.flat:
        ax.axis('off')
        
    plt.tight_layout()
    plt.show()