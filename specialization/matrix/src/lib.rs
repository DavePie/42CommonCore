pub mod matrix;
pub mod vector;

#[cfg(test)]
mod tests {
    use matrix::Matrix;
    use vector::Vector;

    use super::*;

    #[test]
    fn vector_index() {
        let temp = vector![0, 1, 2];
        assert_eq!(temp[0], 0);
        assert_eq!(temp[2], 2);
    }

    #[test]
    #[should_panic]
    fn bad_access_vector() {
        let temp = vector![0, 1, 2];
        temp[3];
    }

    #[test]
    fn add_vector() {
        let temp = vector![0, 1, 2];
        let temp2 = vector![0, 1, 2];
        let temp3 = temp2 + temp;
        let added = vector![0, 2, 4];
        assert!(temp3 == added);
    }

    #[test]
    fn subtract_vector() {
        let temp = vector![0, 1, 2];
        let temp2 = vector![0, 1, 2];
        let temp3 = temp2 - temp;
        let added = vector![0, 0, 0];
        assert!(temp3 == added);
    }

    #[test]
    fn matrix_index() {
        let temp = matrix!(1, 2, 3; 4, 5, 6; 7, 8, 9);
        assert_eq!(temp[0][0], 1);
        assert_eq!(temp[2][2], 9);
        assert_eq!(temp[1][0], 4);
    }

    #[test]
    fn matrix_add() {
        let temp = matrix!(1, 2, 3; 4, 5, 6; 7, 8, 9);
        let temp2 = matrix!(1, 2, 3; 4, 5, 6; 7, 8, 9);
        let temp3 = temp + temp2;
        assert_eq!(temp3[0][0], 2);
        assert_eq!(temp3[0][1], 4);
        assert_eq!(temp3[2][2], 18);
    }
}
