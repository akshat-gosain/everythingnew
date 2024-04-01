# ICM and DQN 

Hey there! So, I was trying to get this ICM thingy working with a DQN on Mujoco's Hopper environment. It was a bit of a wild ride, so here's the lowdown:

## The Code

I wrote some classes for the different parts of the model:

1. `Encoder`: This is a CNN that squishes the environment states down into a smaller size.
2. `InverseModel`: This is an MLP that tries to guess what action got us from one state to the next.
3. `ForwardModel`: This is another MLP that tries to predict what the next state will be given the current state and action.
4. `ICM`: This is where the magic happens. It brings together the Encoder, InverseModel, and ForwardModel.
5. `DQN`: This is the overall model. It's got the ICM and a Q-network inside it.
6. `train_icm_dqn`: This is the function that trains everything.

## What I Tried

I started by defining all the parts of the model and then tried to bring them all together in the training loop.

## The Bumps Along the Way

There were a bunch of errors:

1. **Model Dimensions**: I had to make sure the dimensions of the state and action spaces matched the Mujoco's Hopper environment. I kinda overlooked this at first.
2. **Data Shape**: I kept getting this `RuntimeError` because the input to the `conv2d` operation in the `Encoder` class was the wrong shape. Turns out `conv2d` is super picky about input shapes.
3. **Missing Arguments**: I kept getting this `TypeError` because I forgot to pass `num_frames` when I was creating instances of the `ForwardModel` and `ICM` classes.

I made some progress, but I ran out of time before I could fix everything.

## What's Next?

I'm gonna take another crack at this when I get some time. I need to fix the remaining issues, fine-tune the model parameters, and test it on the Mujoco's Hopper environment.

