use std::ops::{Index, IndexMut};

use crate::vector::Vector;

pub struct Matrix<K> {
    cols: Vec<K>,
    m: usize,
    n: usize,
}

impl<K> Matrix<K> {
    pub fn new(cols: Vector<K>) -> Self {
		let n = cols.len();
		
        Matrix { cols }
    }

    pub fn len(&self) -> usize {
        self.elements.len()
    }

    pub fn get(&self, index: usize) -> Option<&K> {
        self.elements.get(index)
    }
}

impl<K> Index<usize> for Matrix<K> {
    type Output = K;

    fn index(&self, index: usize) -> &Self::Output {
        &self.elements[index]
    }
}

impl<K> IndexMut<usize> for Matrix<K> {
    fn index_mut(&mut self, index: usize) -> &mut Self::Output {
        &mut self.elements[index]
    }
}
