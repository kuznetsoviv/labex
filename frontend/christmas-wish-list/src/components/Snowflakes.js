import "./Snowflakes.css";

const Snowflakes = () => {
    const snowflakes = Array.from({ length: 200 }).map((_, index) => (
        <div
            key={index}
            className="snowflake"
            style={{
                left: `${Math.random() * 100}vw`,
                animationDuration: `${Math.random() * 3 + 2}s`,
                animationDelay: `${Math.random() * 5}s`
            }}
        >
            ❅
        </div>
    ));

    return <div className="snow-container">{snowflakes}</div>;
};

export default Snowflakes;