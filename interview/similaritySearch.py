class SimilarityService:
    def __init__(self, scorer, embeddingLocation: str, modelName: str = "defaultEmbeddingModelName"):
    # Load all the embeddings and store variables in self
        self.scorer = scorer or self.scorer
        self.cveEmbeddings = embeddings.load_embeddings(embeddingLocation)
        self.data = cveData
    def cosineSimilarity(self, queryEmbedding, cveEmbedding):
    # code to find similarity using numpy cosine function
        pass
    def defaultScorer(self, similarityScore: float, metadata: dict):
    # implement mathematical formula to calculate cummulative score based on similarity score and metadata
        pass
    def search(self, q:str, topK:int):
    # convert the query into embedding using sbert library
        queryEmbedding = embeddings.generateEmbedding(q)
        listOfCVEs = []
        for idx, embedding in enumerate(self.cveEmbeddings):
            similarity = self.cosineSimilarity(queryEmbedding, embedding)
            cumulativeScore = self.scorer(similarity, self.data)
            listOfCVEs.append({"score":cumulativeScore, "id":idx})
        orderedList = sorted(listOfCVEs, key="score")
        orderedList = orderedList[:topK]
        return orderedList