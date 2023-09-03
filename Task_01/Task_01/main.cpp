#include <iostream>
#include <vector>
#include <memory>

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {};
    ~tridiagonal_matrix() { std::cout << "\ndestructor called\n"; }

    // clone()
    //возвращает std::unique_ptr
    std::unique_ptr<tridiagonal_matrix> clone() {
        //copy obj to the new
        //create pointer to new obj (unique_ptr)
        auto new_ptr1 = std::unique_ptr<tridiagonal_matrix> (new tridiagonal_matrix(*this));
        return new_ptr1;
    }
   
};

int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );

    auto matrix_clone = matrix->clone(); //must return unique pointer
    auto down_n = matrix_clone->m_down;
    auto upper_n = matrix_clone->m_upper;

    for (auto el : down_n) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    for (auto el : upper_n) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
    std::cout << matrix << " " << matrix_clone;

    return 0;
}