#include <iostream>
#include <string>


using namespace std;

struct RGB {
    int r;
    int g;
    int b;
};

// Check if RGB values are within 0-255 range
bool isValidRGB(const RGB& color) {
    return (color.r >= 0 && color.r <= 255) &&
           (color.g >= 0 && color.g <= 255) &&
           (color.b >= 0 && color.b <= 255);
}

// Calculate WCAG relative luminance directly from RGB
double luminance(int r, int g, int b) {
    auto convert = [](int channel) {
        double v = channel / 255.0;
        return (v <= 0.03928) ? (v / 12.92) : pow((v + 0.055) / 1.055, 2.4);
    };

    double rs = convert(r);
    double gs = convert(g);
    double bs = convert(b);

    return rs * 0.2126 + gs * 0.7152 + bs * 0.0722;
}

// Calculate WCAG contrast ratio
double calculateContrastRatio(double l1, double l2) {
    double lighter = max(l1, l2);
    double darker = min(l1, l2);
    return (lighter + 0.05) / (darker + 0.05);
}

int main() {
    char restart;
    do{
        RGB color1, color2;

    // Get RGB input for Color 1
        cout << "Enter First Color RGB values (0-255):\n";
        cout << "R: "; cin >> color1.r;
        cout << "G: "; cin >> color1.g;
        cout << "B: "; cin >> color1.b;

    // Get RGB input for Color 2
        cout << "\nEnter Second Color RGB values (0-255):\n";
        cout << "R: "; cin >> color2.r;
        cout << "G: "; cin >> color2.g;
        cout << "B: "; cin >> color2.b;

    // Validate inputs
        if (!isValidRGB(color1) || !isValidRGB(color2)) {
            cout << "\nError: RGB values must be between 0 and 255!" << endl;
        }else {
    // Calculate relative luminance
        double color1luminance = luminance(color1.r, color1.g, color1.b);
        double color2luminance = luminance(color2.r, color2.g, color2.b);

    // Calculate contrast ratio
        double ratio = calculateContrastRatio(color1luminance, color2luminance);

    // Evaluate exclusively for AAA (7:1)
        cout << "\n--- Color Contrast Check ---" << endl;
        cout << "Contrast Ratio: " << ratio << ":1\n";
        if (ratio >= 7.0){
            cout << "Results: PASS - These colors meet the AAA contrast standards\n";
        } else if (ratio >= 4.5) {
            cout << "Results: PASS - These colors meet the AA contrast standards\n";
        } else{
            cout << "Results: FAIL - These colors do not meet the AAA contrast standards\n";
            cout << "Try picking a new combination of colors. ";
        }
    }    

    cout << "Would you like to test another set of colors? (y/n): \n";
    cin >> restart;

    }while (restart == 'y' || restart == 'Y');
    
    return 0;
}
