# LLMs for Stock Prediction: Sentiment Market Analysis of News (Source Code)

In this project, I leveraged Light Language Models (LLMs) to predict stock prices by analyzing the latest news articles related to specific stocks. Here are the key components:

1. **Data Collection and Summarization**:
   - I scraped the most recent news articles associated with a stock using Beautiful Soup.
   - To create concise summaries, I employed light models like BART (Bidirectional and Auto-Regressive Transformers).

2. **Feature Extraction with LLMs**:
   - LLMs, including Llama 2 8B, were instrumental in extracting various features from the summarized news articles. These features included sentiment scores, relevance indicators, and biasness scores.

3. **Stock Price Prediction**:
   - The end-to-end project involved predicting stock prices based on the analyzed news articles.
   - I utilized Llama 2 and Llama 3, along with BART, to enhance prediction accuracy.

4. **Dataset Creation and Model Training**:
   - I curated datasets containing features extracted by LLMs from the past 100 days of news data.
   - These datasets were used to train, test, and fine-tune classifier models for stock price prediction.

5. **Collaboration and Mentoring**:
   - Beyond the stock prediction project, I contributed to designing and mentoring other initiatives, including voice sentiment analysis and an AI chatbot for different teams.