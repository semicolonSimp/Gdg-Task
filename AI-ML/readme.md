# Placement Readiness Predictor

A Machine Learning classification project using the **Placement Readiness Dataset provided by GDG-USAR** to predict student placement readiness.

## Objective

* Clean and preprocess the dataset
* Encode categorical features
* Train binary classification models
* Compare models using Precision, Recall, F1-score and Accuracy
* Make an example prediction

## Preprocessing

* Removed unnecessary columns: `name`, `email`, `opinion`
* Handled missing values
* One-hot encoded categorical features
* Converted inconsistent backlog values such as `2+`, `3+` into numeric values
* Applied train-test split and feature scaling

## Models

* Logistic Regression
* K-Nearest Neighbors (KNN)
* Naive Bayes

## Results

| Model               | Precision | Recall |    F1 | Accuracy |
| ------------------- | --------: | -----: | ----: | -------: |
| Logistic Regression |     0.677 |  0.667 | 0.672 |    69.9% |
| KNN                 |     0.990 |  0.988 | 0.989 |    99.0% |
| Naive Bayes         |     0.537 |  0.965 | 0.690 |   59.95% |

## Example Prediction

The trained model takes a student's academic, technical and skill-related features and predicts the corresponding placement-readiness class.

## Tech Stack

**Python, Pandas, NumPy, Scikit-learn, Matplotlib, Seaborn**

## Project Workflow

`Data → Cleaning → Encoding → Train/Test Split → Scaling → Model Training → Evaluation → Prediction`

## Key Decision

The `backlogs` column contained values like `2+` and `3+`. These were converted to numeric lower-bound values (`2+ → 2`, `3+ → 3`) so that ML models could process the feature.
