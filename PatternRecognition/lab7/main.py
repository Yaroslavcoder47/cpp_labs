# Полный код для выполнения лабораторной работы
import cv2
import numpy as np
import matplotlib.pyplot as plt


def add_salt_and_pepper(image, prob=0.01):
    output = np.copy(image)
    total_pixels = image.size
    num_salt = int(total_pixels * prob / 2); num_pepper = num_salt
    coords_s = [np.random.randint(0, i - 1, num_salt) for i in image.shape]
    output[tuple(coords_s)] = 255
    coords_p = [np.random.randint(0, i - 1, num_pepper) for i in image.shape]
    output[tuple(coords_p)] = 0
    return output

def add_gaussian_noise(image, mean=0, sigma=25):
    img_float = image.astype(np.float64) / 255.0
    gaussian = np.random.normal(mean, sigma/255.0, img_float.shape)
    noisy_img = img_float + gaussian
    noisy_img = np.clip(noisy_img, 0.0, 1.0)
    return (noisy_img * 255).astype(np.uint8)


#--- Показ результатов ---
image_path = 'image.jpg'
original_img = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)

if original_img is None:
    print(f"Ошибка: Не удалось загрузить изображение по пути: {image_path}. Проверьте путь.")
else:
    # Полутоновое с Гауссовским шумом
    noisy_gaussian = add_gaussian_noise(original_img, sigma=20)
    
    # Бинарное изображение с шумом "Соль и перец"
    _, binary_base = cv2.threshold(original_img, 127, 255, cv2.THRESH_BINARY)
    noisy_sp = add_salt_and_pepper(binary_base, prob=0.02)
    
    # ДЛЯ ПОЛУТОНОВОГО (Gaussian Noise)
    denoised_avg = cv2.blur(noisy_gaussian, (3, 3))
    denoised_gauss = cv2.GaussianBlur(noisy_gaussian, (3, 3), 0)
    
    # ДЛЯ БИНАРНОГО (Salt-and-Pepper Noise)
    kernel_med = 3
    denoised_median = cv2.medianBlur(noisy_sp, kernel_med)
    
    kernel_morph = np.ones((3, 3), np.uint8)  # Морфологическая обработка с ядром 3
    denoised_opening = cv2.morphologyEx(noisy_sp, cv2.MORPH_OPEN, kernel_morph) # Открытие(Opening) композиция Эрозии и Расширения (Dilation) 

    fig, axes = plt.subplots(2, 4, figsize=(15, 10))
    
    axes[0, 0].imshow(original_img, cmap='gray'); axes[0, 0].set_title('Исходное GrayScale')
    axes[0, 1].imshow(noisy_gaussian, cmap='gray'); axes[0, 1].set_title('Зашумленное (Gaussian)')
    axes[0, 2].imshow(denoised_gauss, cmap='gray'); axes[0, 2].set_title('Устранено (Gaussian Filter, 3x3)')
    axes[0, 3].imshow(denoised_avg, cmap='gray'); axes[0, 3].set_title('Устранено (Median Filter, 3x3)')
    
    axes[1, 0].imshow(binary_base, cmap='gray'); axes[1, 0].set_title('Исходное Бинарное')
    axes[1, 1].imshow(noisy_sp, cmap='gray'); axes[1, 1].set_title('Зашумленное (Salt & Pepper)')
    axes[1, 2].imshow(denoised_median, cmap='gray'); axes[1, 2].set_title('Устранено (Median Filter, 3)')
    axes[1, 3].imshow(denoised_opening, cmap='gray'); axes[1, 3].set_title('Устранено (Opening Filter, 3)')
    
    for ax in axes.flat:
        ax.axis('off')
        
    plt.tight_layout()
    plt.show()