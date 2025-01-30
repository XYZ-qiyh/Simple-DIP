#include <iostream>
#include <string>

#include "src/image.h"
#include "src/utils.h"

void print_help() {

}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("usage: %s image_path\n", argv[0]);
        return -1;
    }

    std::string image_path = argv[1];
    std::cout << "input: " << image_path << std::endl;

    // Digital image Processing
    image im = load_image_color((char *)image_path.c_str(), 0, 0);
    image im_crop = random_crop_image(im, (im.w / 2), (im.h / 2));
    image im_gray = grayscale_image(im);
    image im_soble_edge = sobel_edge_detection(im);
    image im_blur = average_blur(im);
    // TODO: Gaussian Blur
    rgbgr_image(im);

    // get the filename without path & postfix
    std::string filename = getFilenameWithoutExtension(image_path);
    std::cout << "filename: " << filename << std::endl;

    // mkdir if not exists
    std::string output_dir = "./results";
    if(!createDirectoryIfNotExists(output_dir)) {
        std::cerr << "mkdir error!" << std::endl;
    }

    // save results
    std::string out_path = output_dir + "/" + filename + "_cropped";
    //save_image(im_crop, (char *)out_path.c_str());

    out_path = output_dir + "/" + filename + "_gray";
    save_image(im_gray, (char *)out_path.c_str());

    out_path = output_dir + "/" + filename + "_sobel";
    save_image(im_soble_edge, (char *)out_path.c_str());

    out_path = output_dir + "/" + filename + "_blur";
    save_image(im_blur, (char *)out_path.c_str());

    // free image data
    free_image(im);
    free_image(im_crop);
    free_image(im_gray);
    free_image(im_soble_edge);

    return 0;
}