# LSTM-MoE Language Model

## Overview
This project implements a language model with a unique architecture combining LSTM layers and a Mixture-of-Experts (MoE) layer. The model is evaluated on two NLP tasks: Named Entity Recognition (NER) using the CoNLL-2003 dataset, and Question Answering (QA) using the SQuAD 1.1 dataset.

## Architecture
- Two stacked LSTM layers for sequence processing.
- An intermediate MoE layer with a customizable number of experts to enhance model capacity.

## Datasets
- NER: CoNLL-2003 dataset.
- QA: SQuAD 1.1 dataset.

## Usage
The code includes model definitions, data preprocessing, and training/evaluation loops. Adjust the `num_experts` parameter in the MoE layer to explore the impact on performance.

## Results
Performance comparisons between the MoE-augmented model and a baseline model are pending further experimentation.

## Quick Start
- Ensure PyTorch and the `datasets` library are installed.
- Run the provided scripts to train and evaluate the models.

## Contact
For questions or contributions, please open an issue or a pull request.
