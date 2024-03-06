# Various stages through which I struggled and then eventually finally made it a success.

- First experimented a lot with VGG models like VGG16, tried a lot of models and adjusting a lot of hyperparameters.

- But eventually, after getting unsatisfactory post training results, over and over again, I left VGG.

- I moved to ResNet models like Resnet18 or ResNet34.

- All my older failed scrap attempts are also in the folder failed scrap attempts, it took more than 3-4 days to finally get a good enough result.

- Finally managed to get around > 90% accuracy with ResNet18 model by a lot of tinkering.

- Found out some implementations from various online sources that helped me tweak the hyperparameters enough to get this high in accuracy

- After that did multiple iterations of the various layers through sensitivity scans, and from the results decided my pruning parameters

- Did try to implement with the help of some online found code and examples some iterative pruning and fine tuning

- Took a lot of iterations and epochs to finally traverse through all the sparsity levels to figure out the optimal max sparsity with still goood enough close to 90% accuracy

- For the final results was able to reach Global sparsity = 99.122%, while still maintaining model val_accuracy = 88.590%

- This whole process took like more than a week of research and implementing and tweaking various parameters with the gpu running fully blasted almost all the time

- Also as per the bonus task then did plot the weight distributions post and pre pruning the model